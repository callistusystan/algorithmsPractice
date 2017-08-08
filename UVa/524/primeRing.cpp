#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int PRIMES[] = {2,3,5,7,11,13,17,19,23,29,31,37};

void printRings(int cur, int N, vi &curSol) {
  if (cur == N) {
    if (find(PRIMES, PRIMES+12, curSol[N-1] + curSol[0]) != PRIMES + 12) {
      for (int i=0;i<N;i++) {
        if (i) cout << " ";
        cout << curSol[i];
      }
      cout << endl;
    }
  }
  else {
    // try valid values of cur
    for (int i=1;i<=N;i++) {
      bool canUse = false;
      if (cur > 0) {
        if (find(PRIMES, PRIMES+12, i+curSol[cur-1]) != PRIMES + 12)
          canUse = true;
      }
      for (int j=0;j<cur;j++)
      if (curSol[j] == i) {
        canUse = false;
        break;
      }

      if (canUse) {
        curSol[cur] = i;
        printRings(cur+1, N, curSol);
      }
    }
  }

}

void solve(int N) {
  vi curSol(N);
  curSol[0] = 1;

  printRings(1, N, curSol);
}

int main() {
  int N,T = 1;
  while (cin >> N) {
    if (T > 1) cout << endl;
    printf("Case %d:\n", T++);
    solve(N);
  }
  return 0;
}
