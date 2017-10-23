#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int E,N;
vi S(1e3+5);

int rec(int id, int honor, vector<vi> &memo) {
  if (id == N && honor == 0) return 0;
  if (id == N && honor > 0) return -1e6;
  if (memo[id][honor] != -1) return memo[id][honor];

  memo[id][honor] = -1e6;
  // dance
  memo[id][honor] = max(memo[id][honor], rec(id+1, honor-1, memo) - S[id]);
  cerr << "it cost " << rec(id+1, honor-1, memo) - S[id] << " to dance against " << id << endl;
  // truce
  memo[id][honor] = max(memo[id][honor], rec(id+1, honor, memo));
  cerr << "it cost " << rec(id+1, honor, memo) - S[id] << " to truce against " << id << endl;
  // recruit
  memo[id][honor] = max(memo[id][honor], rec(id+1, honor, memo)+S[id]);
  cerr << "it cost " << rec(id+1, honor, memo) + S[id] << " to recruit against " << id << endl;

  return memo[id][honor];
}

void solve() {
  cin >> E >> N;
  for (int i=0;i<N;i++) cin >> S[i];
  vector<vi> memo(N+5, vi(N+5,-1));

  for (int i=N;i>0;i--) {
    cerr << "see if we can get " << i << endl;
    if (E + rec(0, i, memo) > 0) {
      cout << i << endl;
      return;
    }
  }
  cout << 0 << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
