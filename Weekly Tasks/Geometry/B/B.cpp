#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI = acos(-1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vector<ll> R(N);
  for (int i=0;i<N;i++) {
    cin >> R[i];
  }

  sort(R.begin(), R.end());

  ll ans = R[N-1]*R[N-1];
  for (int i=1;i<N;i++) {
    int j = N-1-i;
    if (i%2 == 1) ans -= R[j]*R[j];
    else ans += R[j]*R[j];
  }

  cout << fixed << setprecision(10) << 1.0*ans*PI << endl;

  return 0;
}
