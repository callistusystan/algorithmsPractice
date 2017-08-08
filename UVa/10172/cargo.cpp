#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int N; size_t S, Q; cin>>N>>S>>Q;

  int NCargo = 0;
  vector<queue<int>> Q_i(N+5);
  for (int i=0;i<N;i++) {
    int S; cin >> S;
    for (int j=0;j<S;j++) {
      int dest; cin >> dest; dest--;
      NCargo++;
      Q_i[i].push(dest);
    }
  }


  stack<int> cargo;
  int pos = 0, ans=0;
  while (NCargo) {
    // cerr << "at pos " << pos << endl;
    // unload cargo
    // if cargo for cur pos, plat A
    // put at end of plat B
    // stop when plat B full or stack empty
    while ((!cargo.empty() && cargo.top() == pos) || (!cargo.empty() && Q_i[pos].size() < Q)) {
      ans++;
      int cur = cargo.top();cargo.pop();
      // cerr << "unloaded " << cur << endl;
      if (cur != pos) Q_i[pos].push(cur);
      else NCargo--; // cerr << "shipped " << endl;
    }

    // load from front of plat B
    // stop when plat B empty or stack full
    while (!Q_i[pos].empty() && cargo.size() < S) {
      ans++;
      int cur = Q_i[pos].front(); Q_i[pos].pop();
      // cerr << "loaded " << cur << endl;
      cargo.push(cur);
    }

    if (NCargo == 0) break;

    // move to next pos
    pos = (pos+1)%N;
    ans += 2;
  }

  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
