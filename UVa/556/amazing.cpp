#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vector<string> maze;
vvi visited;
// 0 E, 1 N, 2 W, 3 S
vi hor = {1,0,-1,0};
vi ver = {0,-1,0,1};

bool canMove(int i, int j) {
  return maze[i][j] != '1';
}

int myMod(int a, int b) {
  return (a+b)%b;
}

void solve(int B, int W) {
  maze.resize(B+2);
  visited.resize(B+2);

  fill(maze.begin(), maze.end(), string(W+2, '1'));
  fill(visited.begin(), visited.end(), vector<int>(W+2, 0));
  for (int i=0;i<B;i++) {
    for (int j=0;j<W;j++) {
      cin >> maze[i+1][j+1];
    }
  }

  int i, j;
  i=B;  j=1;
  // direction east, rightWall south initially
  int direction = 0, rightWall = 3;
  do {
    //cerr << direction << endl;
    //cerr << i << " " << j << endl;
    // if no right wall, change direction to rightWall and move,
    int rightWallI = i+ver[rightWall], rightWallJ = j+hor[rightWall];
    //cerr << "wall pos " << rightWallI << " " << rightWallJ << endl;
    if (maze[rightWallI][rightWallJ] != '1') {
      //cerr << "finding the wall" << endl;
      direction = rightWall;
      rightWall--;
      rightWall = myMod(rightWall,4);
      visited[i][j]++;
      i += ver[direction]; j += hor[direction];
    }
    // else if deadend, d = (d+1)%4, r = (r+1)%4
    else if (maze[i+ver[direction]][j+hor[direction]] == '1') {
      //cerr << "deadend, so im turning" << endl;
      direction++;
      rightWall++;
      direction = myMod(direction,4);
      rightWall = myMod(rightWall,4);
    }
    // else try to move forward
    else {
      //cerr << "moving forward" << endl;
      visited[i][j]++;
      i += ver[direction]; j += hor[direction];
    }
  } while (!(i == B && j == 1));

  vi ans(5,0);
  for (int i=1;i<=B;i++) {
    for (int j=1;j<=W;j++) {
      if (visited[i][j] >= 0 && visited[i][j] <= 4 && maze[i][j] == '0') {
        ans[visited[i][j]]++;
      }
    }
  }

  for (int i=0;i<5;i++)
    printf("%3d", ans[i]);
  cout << endl;
}

int main() {
  int B, W;
  while (cin >> B >> W, B || W) {
    solve(B, W);
  }
  return 0;
}
