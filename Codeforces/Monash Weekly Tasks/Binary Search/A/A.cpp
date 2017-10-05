#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int N, M;
  cin >> N;
  vi a(N);
  for (int i=0;i<N;i++) {
    cin >> a[i];
    if (i) a[i] += a[i-1];
  }
  cin >> M;
  for (int i=0;i<M;i++) {
    int q_i; cin >> q_i;
    cout << (lower_bound(a.begin(), a.end(), q_i)-a.begin()+1) << endl;
  }
  return 0;
}
