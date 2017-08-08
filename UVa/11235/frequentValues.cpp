#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class SegmentTree { // the segment tree is stored like a heap array
  private: vi st, A; // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; } // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) { // O(n)
    if (L == R) // as L == R, either one is fine
    {
      st[p] = A[L]; // store the index
      cout << "L: " << L << " R: " << R << " has value " << st[p] << endl;
    }
    else { // recursively compute the values
      build(left(p) , L , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R );

      // get most freq appear element left and right
      auto bounds = equal_range (A.begin()+L, A.begin()+R +1, st[left(p)]);
      int f1 = bounds.second - bounds.first;

      bounds = equal_range (A.begin()+L, A.begin()+R+1, st[right(p)]);
      int f2 = bounds.second - bounds.first;
      if (f1 > f2) st[p] = st[left(p)];
      else st[p] = st[right(p)];

      cout << "L: " << L << " R: " << R << " has value " << st[p] << endl;
      cout << f1 << " " << f2 << endl;
    }
  }
  int query(int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];
    // compute the min position in the left and right part of the interval
    int p1 = query(left(p) , L , (L+R) / 2, i, j);
    int p2 = query(right(p), (L+R) / 2 + 1, R , i, j);
    // get freq of left and right
    auto bounds = equal_range (A.begin()+L, A.begin()+R+1, p1);
    int f1 = bounds.second - bounds.first;

    bounds = equal_range (A.begin()+ L, A.begin()+R+1, p2);
    int f2 = bounds.second - bounds.first;
    if (f1 > f2) return p1;
    else return p2;

  }
  public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size(); // copy content for local usage
    st.assign(4 * n, 0); // create large enough vector of zeroes
    build(1, 0, n - 1); // recursive build
  }
  int query(int i, int j) { return query(1, 0, n - 1, i, j); } // overloading
};

void solve(int N) {
  int Q; cin >> Q;
  vi nums(N);
  for (int i=0;i<N;i++) cin >> nums[i];

  SegmentTree tree(nums);

  for (int i=0;i<Q;i++) {
    int l,r; cin >> l >> r; l--;r--;
    int ans = tree.query(l,r);
    cout << ans << endl;
  }
}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
