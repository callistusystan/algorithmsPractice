#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

template<typename T> struct FenwickTree {
  int N; vector<T> A;
  FenwickTree(int n): N(n+1), A(N) {}
  T rq(int b) {
    int r=0;
    for (;b;b-=b&-b)
      r+=A[b];
    return r;
  }

  T rq(int a,int b) {
    return rq(b)-rq(a);
  }

  void adjust(int i, T v) {
    for (i++;i<N;i+=i&-i)
      A[i] += v;
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  int T; cin >> T;
  while(T--) {
    int N, Q; cin >> N >> Q;
    FenwickTree<ll> f(N);
    for (int i=0;i<N;i++) {
      ll num; cin >> num;
      ll c = 0;
      while (num > 1) {
        if (num % 2 == 0) c++;
        else c+=2;
        num /= 2;
      }
      f.adjust(i,c);
    }
    for (int i=0;i<Q;i++) {
      int a,b; cin >> a >> b;
      a--;
      cout << f.rq(a,b) << endl;

    }
  }
  return 0;
}
