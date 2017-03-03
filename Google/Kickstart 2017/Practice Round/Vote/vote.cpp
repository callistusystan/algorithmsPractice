#include <bits/stdc++.h>

using namespace std;

vector<long long> allFactorials(4005, -1);

long long factorial(int n) {
  if (n == 0) {
    allFactorials[0] = 1;
  } else if (allFactorials[n] == -1) {
    allFactorials[n] = n*factorial(n-1);
  }
  return allFactorials[n];
}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    double N, M;
    cin >> N >> M;
    printf("Case #%d: %.8f\n", t, (N-M)/(N+M));
  }
  return 0;
}
