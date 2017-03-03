#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/permutation-equation

int main() {
  int N;
  cin >> N;

  vector<int> p(N+1);
  vector<int> pInv(N+1);

  for (int i=1;i<=N;i++) {
    cin >> p[i];
    pInv[p[i]] = i;
  }
  for (int i=1;i<=N;i++) {
    cout << pInv[pInv[i]] << endl;
  }
  return 0;
}
