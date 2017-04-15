#include <bits/stdc++.h>

using namespace std;

void move(string &state, int i, int K) {
  for (int j=i;j<i+K;j++) {
    state[j] = (state[j] == '+') ? '-' : '+';
  }
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    string state;
    int K, N;
    cin >> state >> K;

    N = state.size();

    cout << "Case #" << t << ": ";

    int ans = 0;
    for (int i=0;i<=N-K;i++) {
      if (state[i] == '-') {
        move(state, i, K);
        ans++;
      }
    }

    int nMinus = count(state.begin(), state.end(), '-');
    if (nMinus == 0) cout << ans;
    else cout << "IMPOSSIBLE";

    cout << endl;
  }
  return 0;
}
