#include <bits/stdc++.h>

using namespace std;

int main() {
  int C;
  cin >> C;
  while (C--) {
    int L, M;
    cin >> L >> M;
    L *= 100;

    vector<queue<int>> q(2);
    for (int i=0;i<M;i++) {
      int l;
      string bank;
      cin >> l >> bank;

      if (bank == "left") {
        q[0].push(l);
      } else {
        q[1].push(l);
      }
    }

    int bank = 0, ans = 0;

    // loop until both queues are empty
    while (!(q[0].empty() && q[1].empty())) {
      int remaining = L;
      // load cars till no more space
      while (!q[bank].empty() && q[bank].front() < remaining) {
        remaining -= q[bank].front();
        q[bank].pop();
      }

      // go to other bank
      bank^=1;
      ans++;
    }

    cout << ans << endl;
  }
  return 0;
}
