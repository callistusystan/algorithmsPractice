#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/between-two-sets

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  vector<int> B(M);

  for (int i=0;i<N;i++)
    cin >> A[i];
  for (int i=0;i<M;i++)
    cin >> B[i];

  int count = 0;

  for (int i=1;i<=100;i++) {
    bool valid = true;
    for (int a=0;a<N;a++) {
      if (i%A[a] != 0) {
        valid = false;
        break;
      }
    }
    for (int b=0;b<M;b++) {
      if (!valid || B[b]%i != 0) {
        valid = false;
        break;
      }
    }
    if (valid)
      count++;
  }

  cout << count << endl;
  return 0;
}
