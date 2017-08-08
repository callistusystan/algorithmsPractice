#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

pair<vi, int> chooseTracks(int cur, int used, vi &sol, int N, vi &tracks) {
  if (cur == (int)tracks.size()) return make_pair(sol, used);

  // try not taking, then try taking if it wont exceed N
  pair<vi, int> ansIfNoTake = chooseTracks(cur+1, used, sol, N, tracks);
  if (used + tracks[cur] <= N) {
    sol.push_back(cur);
    pair<vi, int> ansIfTake = chooseTracks(cur+1, used+tracks[cur], sol, N, tracks);
    sol.pop_back();
    if (ansIfTake.second > ansIfNoTake.second) {
      return ansIfTake;
    }
  }

  return ansIfNoTake;
}

void solve(int N) {
  int T; cin >> T;
  vi tracks(T);
  for (int i=0;i<T;i++) cin >> tracks[i];

  vi curSol;
  pair<vi, int> tracksToChoose = chooseTracks(0, 0, curSol, N, tracks);

  for (int t : tracksToChoose.first) {
    cout << tracks[t] << " ";
  }
  printf("sum:%d\n", tracksToChoose.second);
}

int main() {
  int N;
  while (cin >> N) {
    solve(N);
  }
  return 0;
}
