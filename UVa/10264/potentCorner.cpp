#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N) {
  vi weights(1<<N);
  vi potencies(1<<N,0);
  for (int i=0;i<(1<<N);i++) {
    cin >> weights[i];
  }

  for (int i=0;i<(1<<N);i++) {
    for (int j=0;j<N;j++) {
      int neighbour = i ^ (1<<j);
      potencies[i] += weights[neighbour];
    }
  }
  int ans = 0;

  for (int i=0;i<(1<<N);i++) {
    for (int j=0;j<N;j++) {
      int neighbour = i ^ (1<<j);
      ans = max(ans, potencies[i]+potencies[neighbour]);
    }
  }

  cout << ans << endl;
}

int main() {
  int N;
  while (cin >> N) {
    solve(N);
  }
  return 0;
}
