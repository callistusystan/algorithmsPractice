#include <bits/stdc++.h>

using namespace std;

double solve() {
  int D, N;
  cin >> D >> N;

  vector<int> K(N), S(N);
  for (int i=0;i<N;i++) {
    cin >> K[i];
    cin >> S[i];
  }
  double maxHours = -1;
  for (int i=0;i<N;i++) {
    double remaining = D-K[i];
    double hoursNeeded = remaining/S[i];
    maxHours = max(maxHours, hoursNeeded);
  }
  return D/maxHours;
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    printf("Case #%d: %lf\n", t, solve());
  }
  return 0;
}
