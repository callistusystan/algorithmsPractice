#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void solve() {
  ll N, tmp, next, K; cin >> N;
  tmp = N;
  K = 1;
  while (tmp > 0) {
    K *= 10;
    tmp /= 10;
  }
  K /= 10;

  next = N/K * K + K;
  cout << next - N << endl;
}

int main() {
  solve();
  return 0;
}
