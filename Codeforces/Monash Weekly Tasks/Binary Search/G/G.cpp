#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
vi a;

int main() {
  cin >> N;
  a.resize(N);

  for (int i=0;i<N;i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int j=0;j<N;j++) {
    if (j > 0 && a[j] == a[j-1]) continue;
    int base = a[j];
    int nextMult = a[j]+base;
    while (1) {
      auto it = lower_bound(a.begin()+j, a.end(), nextMult);
      it--;
      ans = max(ans, (*it) % base);
      nextMult += base;
      if ((it+1) == a.end()) break;
    }
  }

  cout << ans << endl;

  return 0;
}
