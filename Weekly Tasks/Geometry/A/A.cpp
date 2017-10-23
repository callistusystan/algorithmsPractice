#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N; vector<ll> freq(1e5+5), memo(1e5+5, -1);

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;

  while (T--) {
    int a; cin >> a;
    if (360%(180-a) == 0) cout << "YES";
    else cout << "NO";
    cout << endl;
  }

  return 0;
}
