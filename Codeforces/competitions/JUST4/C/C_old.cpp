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

      int lo = 0, hi = i;
      int try1, try2; try1 = try2 = val;
      ans[id] = 0;
      if (lo < hi) {
        while (lo != hi-1) {
          int mid = (lo+hi)/2;
          int res1, res2; res1 = res2 = val;
          add(res1, A[lo].first);
          add(res2, A[mid].first);

          if (res1 < res2) {
            lo = mid;
          } else {
            hi = mid;
          }
        }
        add(try1, A[lo].first);
        ans[id] = max(ans[id], try1);
      }

      lo = i+1, hi = N;
      if (lo < hi) {
        while (lo != hi-1) {
          int mid = (lo+hi)/2;
          int res1, res2; res1 = res2 = val;
          add(res1, A[lo].first);
          add(res2, A[mid].first);

          if (res1 < res2) {
            lo = mid;
          } else {
            hi = mid;
          }
        }
        add(try2, A[lo].first);
        ans[id] = max(ans[id], try2);
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
