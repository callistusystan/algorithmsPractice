#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int MOD = 1e9+7;
vector<pii> A(1e5+5);
vi ans(1e5+5);

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    for (int i=0;i<N;i++) {
      int A_i; cin >> A_i;
      A[i] = {A_i, i};
    }

    sort(A.begin(), A.begin()+N);

    for (int i=0;i<N;i++) {
      pii cur = A[i];
      int val = cur.first, id = cur.second;

      if (i != N-1) ans[id] = (val+A[N-1].first)%MOD;
      else ans[id] = (val+A[N-2].first)%MOD;

      int x = (MOD-1) - val;
      auto it = upper_bound(A.begin(), A.begin() + N, make_pair(x, 1000000));
      int j = it - A.begin();

      if (j > 0) {
        if (i != j-1) {
          ans[id] = max(ans[id], (val + A[j-1].first)%MOD);
        } else if (j -2 >= 0) {
          ans[id] = max(ans[id], (val + A[j-2].first)%MOD);
        }
      }
    }

    for (int i=0;i<N;i++) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << '\n';
  }

  return 0;
}
