#include <bits/stdc++.h>

using namespace std;

int main() {
  int C;
  cin >> C;
  while (C--) {
    int N, T, M;
    cin >> N >> T >> M;

    vector<queue<pair<int, int>>> q(2);
    for (int i=0;i<M;i++) {
      int m;
      string bank;
      cin >> m >> bank;

      if (bank == "left") {
        q[0].push(make_pair(m, i));
      } else {
        q[1].push(make_pair(m, i));
      }
    }

    int bank = 0, curT = 0, curN = 0;

    vector<int> ans(M);

    // loop until both queues are empty
    while (!(q[0].empty() && q[1].empty())) {
      int nextCarArrival = INT_MAX;

      if (!q[0].empty())
        nextCarArrival = q[0].front().first;
      if (!q[1].empty())
        nextCarArrival = min(nextCarArrival, q[1].front().first);

      // if a car has not arrived, wait till a car arrives at either bank
      if (nextCarArrival > curT) {
        curT = nextCarArrival;
      }

      curN = 0;
      // load cars till N or till no more
      while (curN < N && !q[bank].empty() && q[bank].front().first <= curT) {
        ans[q[bank].front().second] = curT + T;
        q[bank].pop();
        curN++;
      }

      // go to other bank
      curT += T;
      bank^=1;
    }

    for (int i : ans) {
      cout << i << endl;
    }

    if (C) cout << endl;

  }
  return 0;
}
