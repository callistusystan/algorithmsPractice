#include <bits/stdc++.h>

using namespace std;

typedef vector<string> vs;

int N, n;
vs big, small;

int count() {
  int count = 0;
  for (int i=0;i<=N-n;i++) {
    for (int j=0;j<=N-n;j++) {
      bool match = true;
      for (int a=0;a<n;a++) {
        for (int b=0;b<n;b++) {
          if (small[a][b] != big[i+a][j+b]) {
            match = false;
            break;
          }
        }
      }

      if (match) count++;
    }
  }
  return count;
}


/*
00 01 02
10 11 12
20 21 22

20 10 00
21 11 01
22 12 02

notice that for a[i][j], j is the same for each row
notice that for a[i][j], i decreases from n-1 to 0 for each row

thus, if we have a simple i,j loop
  we can see the relationship
    small[i][j] = tmp[n-j-1][i]
*/
void rotate() {
  vs tmp = small;

  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      small[i][j] = tmp[n-j-1][i];
    }
  }
}

int main() {
  while (cin >> N >> n, N || n) {
    big.resize(N); small.resize(n);
    for (int i=0;i<N;i++)
        cin >> big[i];

    for (int i=0;i<n;i++)
        cin >> small[i];

    cout << count();
    for (int i=0;i<3;i++) {
      rotate();
      cout << " " << count();
    }
    cout << endl;
  }
  return 0;
}
