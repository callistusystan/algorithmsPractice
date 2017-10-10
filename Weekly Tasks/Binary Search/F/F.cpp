#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

double EPS = 1e-9;
int N, K;
double L, V1, V2;

bool f(double t) {
  if (L/V1 < t - EPS) return true;
  int nGroups = N/K;
  if (N%K != 0) nGroups++;

  // move first group
  double distByBus = (t*V1*V2 - L*V2)/(V1-V2);
  double tByBus = distByBus/V2;
  double posBus = distByBus;
  double tElapsed = tByBus;
  nGroups--;

  while (nGroups > 0) {
    // go back for next group
    double posGroup = tElapsed*V1;
    if (posGroup > L - EPS) break;
    double tMeet = (posBus - posGroup)/(V1+V2);
    double posMeet = posGroup + tMeet*V1;
    tElapsed += tMeet;

    if (L - posMeet < distByBus - EPS) {
      // less than distByBus
      tElapsed += (L-posMeet)/V2;
      posBus = L;

    } else {
      tElapsed += tByBus;
      posBus = posMeet + distByBus;
    }
    nGroups--;
  }

  return tElapsed < t + EPS;
}

int main() {
  cin >> N >> L >> V1 >> V2 >> K;

  double lo = 0, hi = 1e9+5;
  int i = 0;
  while (hi - lo > EPS && i++ < 100) {
    double mid = (lo+hi)/2;
    if (f(mid)) {
      hi = mid;
    }
    else lo = mid;
  }

  cout << fixed << setprecision(10) << hi << endl;
  return 0;
}
