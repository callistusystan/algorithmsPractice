#include <bits/stdc++.h>

using namespace std;

int K, N;
double A, B, C;
map<pair<int, int>, double> memo;

double getExpectedValue(int x, int n) {
  if (n >= N) {
    return x;
  } else if (memo.count(make_pair(x, n))) {
    return memo[make_pair(x, n)];
  }
  double ans = A * getExpectedValue(x&K, n+1) + B * getExpectedValue(x|K, n+1) + C * getExpectedValue(x^K, n+1);

  memo[make_pair(x, n)] = ans;

  return ans;
}

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    memo.clear();
    int x;
    cin >> N >> x >> K >> A >> B >> C;
    A /= 100.0;
    B /= 100.0;
    C /= 100.0;


    double ans = getExpectedValue(x, 0);

    printf("Case #%d: %.10f\n", t, ans);
  }
  return 0;
}
