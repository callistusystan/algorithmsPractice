#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vi nums(1e5+5), start(1e5+5), cnt(1e5+5);
vector<ii> st(4e5 + 5);

void build(int x, int l, int r) {
  if (l == r) {
    st[x] = {l, 1};
  }
  else {
    int mid = (l+r)/2;
    build(2*x, l, mid);
    build(2*x+1, mid+1, r);
    ii lc,rc;
    lc = st[2*x]; rc = st[2*x+1];
    auto p1 = equal_range(nums.begin()+mid+1, nums.begin()+r+1, nums[lc.first]);
    auto p2 = equal_range(nums.begin()+l, nums.begin()+mid+1, nums[rc.first]);
    lc.second += p1.second-p1.first;
    rc.second += p2.second-p2.first;
    if (lc.second >= rc.second)
      st[x] = lc;
    else
      st[x] = rc;
  }
}

ii query(int x, int l, int r, int i, int j) {
  if (r < i || l > j) return {-1,-1};
  if (i <= l && r <= j) return st[x];

  ii lc,rc;
  int mid = (l+r)/2;
  lc = query(2*x,l,mid,i,j);
  rc = query(2*x+1,mid+1,r,i,j);

  if (lc.second == -1) return rc;
  if (rc.second == -1) return lc;

  int end1,start2;
  end1 = start[lc.first]+cnt[start[lc.first]]-1;
  start2 = start[rc.first];

  if (end1 >= mid + 1) lc.second += min(r,end1)-(mid+1)+1;
  if (start2 <= mid) rc.second += mid-max(l, start2)+1;

  if (lc.second >= rc.second) return lc;
  else return rc;
}

bool f(ii a, ii b) {
  if (a.second != b.second) return a.second < b.second;
  return a.first < b.first;
}

void solve(int N) {
  int Q; cin >> Q;
  for (int i=0;i<N;i++)  {
    cin >> nums[i];
    if (i == 0) start[i] = 0;
    else if (nums[i] == nums[i-1]) start[i] = start[i-1];
    else start[i] = i;

    cnt[start[i]]++;
  }

  build(1,0,N-1);

  for (int i=0;i<Q;i++) {
    int l,r; cin >> l >> r; l--;r--;
    if (nums[l] == nums[r]) {
      cout << r-l+1 <<endl;
      continue;
    }

    vector<ii> ans;
    ans.push_back(query(1,0,N-1,l,r));

    cout << (*max_element(ans.begin(), ans.end(), f)).second << endl;
  }
}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
