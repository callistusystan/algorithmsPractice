#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int MAX_SIZE = 1048;
vector<vi> freq(2, vi(MAX_SIZE,0));

/*
cur = 0    cur = 4
_ _ _ _    * _ *     4/2 = 2 changed   3/2 = 1 unchanged
cur = 0    cur = 4
_ _ _ _    * _ * _   5/2 = 2 changed   4/2 = 2 unchanged

cur = 0  cur = 3
_ _ _    _ * _      3/2 = 1 changed    4/2 = 2 unchanged
cur = 0  cur = 3
_ _ _    _ * _ *    4/2 = 2 changed    5/2 = 2 unchanged
*/

int main() {
  int N, K, X; cin >> N >> K >> X;
  for (int i=0;i<N;i++) {
    int num; cin >> num;
    freq[0][num]++;
  }

  int d = 0;
  for (int i=0;i<K;i++) {
    d = 1-d;
    int cur = 0;
    for (int j=0;j<MAX_SIZE;j++) freq[d][j] = 0;
    for (int j=0;j<MAX_SIZE;j++) {
      if (freq[1-d][j]) {
        if (cur%2 == 0) {
          freq[d][j^X] += (freq[1-d][j]+1)/2;
          freq[d][j] += freq[1-d][j]/2;
        } else {
          freq[d][j^X] += (freq[1-d][j])/2;
          freq[d][j] += (freq[1-d][j]+1)/2;
        }
      }
      cur += freq[1-d][j];
    }
  }

  for (int j=MAX_SIZE-1;j>=0;j--) {
    if (freq[d][j]) {
      cout << j << " ";
      break;
    }
  }

  for (int i=0;i<MAX_SIZE;i++) {
    if (freq[d][i]) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
