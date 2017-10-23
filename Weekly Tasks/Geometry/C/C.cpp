#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

double EPS = 1e-9;
double PI = acos(-1);

double D,H,V,E;

void solve() {
  cin >> D >> H >> V >> E;

  double X = 4*V/(PI*D*D);

  if (E >= X - EPS) {
    cout << "NO" << endl;
    return;
  }

  double T = H/(X-E);

  if (T <= 1e4) {
    cout << "YES" << endl;
    cout << T << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
