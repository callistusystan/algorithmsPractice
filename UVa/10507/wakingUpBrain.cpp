#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N) {
  int M; cin >> M;

  string awake, line;
  cin >> awake; cin.ignore();

  vvi adj(26);
  while (getline(cin, line), line != "") {
    int c1, c2; c1 = line[0] - 'A'; c2 = line[1] - 'A';
    adj[c1].push_back(c2); adj[c2].push_back(c1);
  }

  vi status(26,0);
  queue<int> q; for (char c: awake) q.push(c-'A'), status[c-'A'] = 3;
  int ans = 0, remain = N-3;
  while (!q.empty() && remain) {
    vi next;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) {
        status[v]++;
        if (status[v] == 3) {
          remain--;
          next.push_back(v);
        }
      }
    }
    ans++;
    for (int u:next) q.push(u);
  }

  if (remain) cout << "THIS BRAIN NEVER WAKES UP";
  else printf("WAKE UP IN, %d, YEARS", ans);
  cout << endl;
}

int main() {
  int N;
  while (cin >> N) {
    solve(N);
  }
  return 0;
}
