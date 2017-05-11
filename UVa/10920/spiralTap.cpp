#include <bits/stdc++.h>

using namespace std;

int SZ, P, i, j;

void solve() {
  i = j = (SZ+1)/2;
  int curSize,n;
  curSize = 3;
  n = 1;

  while (n != P) {
    // up 1
    i++; n++;
    if (n == P) return;

    // left curSize - 2
    if (P-n > curSize-2) {
      j -= (curSize-2);
    } else {
      j-= (P-n);
      return;
    }
    n+= (curSize-2);

    // down curSize - 1
    if (P-n > curSize-1) {
      i -= (curSize-1);
    } else {
      i-= (P-n);
      return;
    }
    n+= (curSize-1);

    // right curSize - 1
    if (P-n > curSize-1) {
      j += (curSize-1);
    } else {
      j+= (P-n);
      return;
    }
    n+= (curSize-1);

    // up curSize - 1
    if (P-n > curSize-1) {
      i += (curSize-1);
    } else {
      i+= (P-n);
      return;
    }
    n+= (curSize-1);

    curSize += 2;
  }
}

int main() {
  while (cin >> SZ >> P, SZ || P) {
    solve();
    printf("Line = %d, column = %d.\n", i,j);
  }
  return 0;
}
