#include <bits/stdc++.h>

using namespace std;

int R, C, N;
vector<vector<char>> grid1(105, vector<char>(105)), grid2(105, vector<char>(105));

void process(int i, int j, char c) {
  if ((i >= 0 && i < R) && (j >= 0 && j < C)) {
    if (c == 'R' && grid1[i][j] == 'S')
      grid2[i][j] = 'R';
    else if (c == 'S' && grid1[i][j] == 'P')
      grid2[i][j] = 'S';
    else if (c == 'P' && grid1[i][j] == 'R')
      grid2[i][j] = 'P';
  }
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    if (t > 1) cout << endl;
    cin >> R >> C >> N;
    for (int i=0;i<R;i++)
      for (int j=0;j<C;j++)
        cin >> grid1[i][j];

    while (N--) {
      for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
          grid2[i][j] = grid1[i][j];

      for (int i=0;i<R;i++)
        for (int j=0;j<C;j++){
          process(i-1, j, grid1[i][j]);
          process(i+1, j, grid1[i][j]);
          process(i, j-1, grid1[i][j]);
          process(i, j+1, grid1[i][j]);
        }

      for (int i=0;i<R;i++)
        for (int j=0;j<C;j++)
          grid1[i][j] = grid2[i][j];
    }

    for (int i=0;i<R;i++) {
      for (int j=0;j<C;j++) {
        cout << grid1[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
