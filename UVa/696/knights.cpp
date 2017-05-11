#include <bits/stdc++.h>

using namespace std;

void solve(int M, int N) {
  int ans = -1;
  if (M == 1) ans = N;
  else if (M == 2) {
    int n_groups = N/4;
    int remaining_knights = 0;
    if (N%4 == 1) remaining_knights = 2;
    else if (N%4 >= 2) remaining_knights = 4;
    ans = n_groups*4 + remaining_knights;
  }
  else {
    ans = (N*M+1)/2;
  }

  printf("%d knights may be placed on a ", ans);
}

int main() {
  int M, N;
  while (cin >> M >> N, M || N) {
    solve(min(M,N), max(M,N));
    printf("%d row %d column board.\n", M, N);
  }
  return 0;
}
