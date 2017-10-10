#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int VISITED = 1;
int UNVISITED = 0;

int N, M;
vector<string> board;

void dfs(int i, int j, char color) {
  if (i < 0 || i >= N || j < 0 || j >= M) return;
  if (board[i][j] != '.') return;
  board[i][j] = color;

  char nextColor = ((color=='W') ? 'B' : 'W');
  dfs(i-1,j,nextColor);
  dfs(i,j+1,nextColor);
  dfs(i+1,j,nextColor);
  dfs(i,j-1,nextColor);
}

void solve() {
  cin >> N >> M;

  board.resize(N+5);
  for (int i=0;i<N;i++) cin >> board[i];

  for (int i=0;i<N;i++) {
    for (int j=0;j<M;j++) {
      if (board[i][j] == '.')
        dfs(i,j,'B');
    }
  }

  for (int i=0;i<N;i++) {
    cout << board[i] << endl;
  }
}

int main() {
  solve();
  return 0;
}
