#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

double EPS = 1e-6;
int N, K, S, T;
vi capacities, stops;

bool f(int cap) {
  double pos = 0; double tElapsed = 0;
  for (int i=0;i<K;i++) {
    double distToStop = stops[i] - pos;
    if (distToStop > cap) return false;

    // calculate distance needed to use normal mode
    double distNormal = 2*distToStop - cap;

    // if negative, means we can just use accelerated mode
    // make sure to set distNormal to 0
    distNormal = max(distNormal, 0.0);

    // update pos and tElapsed
    pos = stops[i];
    tElapsed += distNormal*2 + (distToStop-distNormal);
  }
  return tElapsed < T + EPS;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K >> S >> T;
  map<int, int> capToCost;

  for (int i=0;i<N;i++) {
    int ci, vi; cin >> ci >> vi;
    if (capToCost.count(vi) == 0) {
      capToCost[vi] = ci;
    }
    capToCost[vi] = min(capToCost[vi], ci);
  }

  for (auto it = capToCost.begin(); it != capToCost.end(); it++) {
    auto p = *it;
    capacities.push_back(p.first);
  }
  N = capacities.size();

  stops.resize(K);
  for (int i=0;i<K;i++) {
    cin >> stops[i];
  }
  sort(stops.begin(), stops.end());
  stops.push_back(S); K++;

  int lo = -1, hi = N;
  int i = 0;
  while (lo != hi-1 && i++ < 50) {
    int mid = lo + (hi-lo)/2;
    if (f(capacities[mid])) hi = mid;
    else lo = mid;
  }

  if (hi == N || i >= 50) cout << -1 << endl;
  else {
    int minCost = 1e9+5;
    for (int i=hi;i<N;i++) {
      minCost = min(minCost, capToCost[capacities[i]]);
    }
    cout << minCost << endl;
  }
  return 0;
}
