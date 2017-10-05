#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

double euc(vi c1, vi c2) {
  double distance = 0;
  for (int i=0;i<3;i++) {
    distance += (c1[i] - c2[i])*(c1[i] - c2[i]);
  }
  return sqrt(distance);
}

void solve() {
  vi c1(3),c2(3),c3(3);
  for (int i=0;i<3;i++) {
    cin >> c1[i];
  }
  for (int i=0;i<3;i++) {
    cin >> c2[i];
  }
  for (int i=0;i<3;i++) {
    cin >> c3[i];
  }

  double maxDistance = 0;
  maxDistance = max(maxDistance, euc(c1,c2));
  maxDistance = max(maxDistance, euc(c1,c3));
  maxDistance = max(maxDistance, euc(c2,c3));

  printf("%.10lf\n", maxDistance/6);
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
