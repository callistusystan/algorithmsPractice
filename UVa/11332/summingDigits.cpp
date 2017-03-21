#include <bits/stdc++.h>

using namespace std;

int g(int n) {
  if (n < 10) {
    return n;
  }
  int sum = 0;
  while (n > 0) {
    sum += n%10;
    n/=10;
  }
  return g(sum);
}

int main() {
  int n;
  while (cin >> n, n) {
    cout << g(n) << endl;
  }
  return 0;
}
