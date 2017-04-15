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
    string initState;
    int K, N;
    cin >> initState >> K;

    N = initState.size();

    int nMinus = count(initState.begin(), initState.end(), '-');

    cout << "Case #" << t << ": ";

    if (nMinus == 0) {
      cout << 0;
    } else {
      int ans = -1;
      map<string, int> distance;
      queue<string> myQ;

      distance[initState] = 0;
      myQ.push(initState);

      while (!myQ.empty()) {
        string curState = myQ.front();
        myQ.pop();

        int curDistance = distance[curState];

        // if end game
        if (count(curState.begin(), curState.end(), '-') == 0) {
          ans = curDistance;
          break;
        }

        for (int i=0;i<=N-K;i++) {
          string nextState = curState;
          move(nextState, i, K);
          if (distance.count(nextState) == 0) {
            distance[nextState] = curDistance + 1;
            myQ.push(nextState);
          }
        }
      }

      if (ans == -1) cout << "IMPOSSIBLE";
      else cout << ans;
    }

    cout << endl;
  }
  return 0;
}
