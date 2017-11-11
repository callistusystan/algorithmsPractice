#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ll N, K; cin >> N >> K;
  vi A(N);
  for (int i=0;i<N;i++) cin >> A[i];

  for (int i=1;i<=N;i++) {
    if (K <= i) {
      cout << A[K-1] << endl;
      break;
    }
    K -= i;
  }

  return 0;
}
