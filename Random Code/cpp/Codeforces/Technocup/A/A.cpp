#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ll N, K; cin >> N>> K;
  ll tmp = N;
  int n2=0,n5=0;
  while (tmp%2 == 0) {
    n2++;
    tmp /= 2;
  }
  while (tmp%5 ==0) {
    n5++;
    tmp/=5;
  }

  ll x = 1;
  for (int i=0;i<K-n2;i++) {
    x *= 2;
  }
  for (int i=0;i<K-n5;i++) {
    x *= 5;
  }
  cout << N * x << endl;
  return 0;
}
