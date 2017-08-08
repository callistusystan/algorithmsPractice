#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int findMinMoves(int cur, vi &rows) {
  if (cur == 8) return 0;

  // try putting it in all locations
  int bestAns = 8;
  int orig = rows[cur];
  for (int i=0;i<8;i++) {
    bool canPut = true;
    for (int j=0;j<cur;j++) {
      if (rows[j] == i || abs(rows[j] - i) == abs(j-cur)) {
        canPut = false;
        break;
      }
    }

    if (canPut) {
      rows[cur] = i;
      int ansIfMoveToI = findMinMoves(cur+1, rows);
      bestAns = min(bestAns, ansIfMoveToI + ((i == orig) ? 0: 1));
    }
  }
  rows[cur] = orig;

  return bestAns;
}

void solve(string line) {
  istringstream istream(line);
  vi rows(8);
  for (int i=0;i<8;i++) {
    istream >> rows[i];
    rows[i]--;
  }

  int ans = findMinMoves(0, rows);

  cout << ans << endl;
}

int main() {
  string line;
  int T = 1;
  while (getline(cin, line)) {
    printf("Case %d: ", T++);
    solve(line);
  }
  return 0;
}
