#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int A,B,C; cin >> A >> B >> C;
  for (int x=-100;x<=100;x++)
    for (int y=-100;y<=100;y++) if (x!=y)
      for (int z=-100;z<=100;z++)
        if (x!=z && y!=z &&
          x+y+z == A &&
          x*y*z == B &&
          x*x + y*y + z*z == C
        ) {
          printf("%d %d %d\n", x, y, z);
          return;
        }
  cout << "No solution." << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
