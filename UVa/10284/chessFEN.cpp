#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vector<string> board;
vvb attacked;

bool isValid(int I, int J) {
  return (I >=0 && I < 8 && J >=0 && J < 8);
}

void setAttacked(int I, int J) {
  if (isValid(I,J)) {
    attacked[I][J] = true;
  }
}

void attackInLine(int I, int J, vi hor, vi ver) {
  int N = hor.size();
  for (int k=0;k<N;k++) {
    int i = I+ver[k];
    int j = J+hor[k];
    while (isValid(i,j) && board[i][j] == '.') {
      setAttacked(i,j);
      i += ver[k];
      j += hor[k];
    }
  }
}

void attackPos(int I, int J, vi hor, vi ver) {
  int N = hor.size();
  for (int i=0;i<N;i++) {
    setAttacked(I+hor[i], J+ver[i]);
  }
}

void process(int I, int J) {
  char piece = board[I][J];
  vi hor, ver;
  switch (piece) {
    case 'p':
      setAttacked(I+1,J-1);
      setAttacked(I+1,J+1);
      break;
    case 'P':
      setAttacked(I-1,J-1);
      setAttacked(I-1,J+1);
      break;
    case 'N':case 'n':
      hor = {1,2, 2, 1,-1,-2,-2,-1};
      ver = {2,1,-1,-2,-2,-1, 1, 2};
      attackPos(I, J, hor, ver);
      break;
    case 'B':case 'b':
      hor = {1,1,-1,-1};
      ver = {1,-1,-1,1};
      attackInLine(I,J, hor, ver);
      break;
    case 'R': case 'r':
      hor = {1,0,-1,0};
      ver = {0,-1,0,1};
      attackInLine(I,J, hor, ver);
      break;
    case 'Q': case 'q':
      hor = {1,1,-1,-1,1,0,-1,0};
      ver = {1,-1,-1,1,0,-1,0,1};
      attackInLine(I,J, hor, ver);
      break;
    case 'k': case 'K':
      hor = {1,1,1,0,-1,-1,-1,0};
      ver = {1,0,-1,-1,-1,0,1,1};
      attackPos(I, J, hor, ver);
      break;
  }
}

void solve(string line) {
  board.resize(8); attacked.resize(8);
  fill(board.begin(), board.end(), "........");
  fill(attacked.begin(), attacked.end(), vector<bool>(8,false));

  // parse input
  int p,i,j;
  p=i=j=0;
  while (p < (int)line.size()) {
    char c = line[p];
    if (c != '/') {
      // if digit, move j up by d-1
      // else place piece on board
      if (isdigit(c)) j+=c-'0'-1;
      else board[i][j] = c;
      // regardless of what happens, increment j
      j++;

      // if j == 8, reset j and increment i
      if (j==8) {
        i++;
        j = 0;
      }
    }

    // increment p
    p++;
  }

  // now that all pieces are placed, process the pieces
  for (int i=0;i<8;i++)
    for (int j=0;j<8;j++)
      if (board[i][j] != '.')
        process(i,j);

  // after processing, count how many unoccupied and not attacked
  int ans = 0;
  for (int i=0;i<8;i++)
    for (int j=0;j<8;j++)
      if (board[i][j] == '.' && !attacked[i][j]) ans++;

  cout << ans << endl;
}

int main() {
  string line;
  while (getline(cin, line)) {
    solve(line);
  }
  return 0;
}
