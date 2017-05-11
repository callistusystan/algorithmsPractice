#include <bits/stdc++.h>

using namespace std;

void solve() {
  char piece; int M, N;
  cin >> piece >> M >> N;

  switch (piece) {
    case 'r':
      cout << min(M,N);
      break;
    case 'k':
      cout << (M*N+1)/2;
      break;
    case 'Q':
      cout << min(M,N);
      break;
    case 'K':
      int rows_with_kings = M/2;
      int cols_with_kings = N/2;
      if (M%2 == 1) rows_with_kings++;
      if (N%2 == 1) cols_with_kings++;

      cout << rows_with_kings*cols_with_kings;
      break;
  }

  cout << endl;

}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
