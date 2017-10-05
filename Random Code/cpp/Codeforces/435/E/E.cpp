#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string s; cin >> s;
  vector<ll> freq(26,0);
  for (char c : s) {
    freq[c-'a']++;
  }

  int biggest = *max_element(freq.begin(), freq.end());

  ll ans = -1; int X = 2;
  for (int i=2;i<=max(2,biggest)+5;i++) {
    ll curVal = 0;
    for (int j=0;j<26;j++) {
      curVal += (freq[j]%i)*freq[j];
    }
    if (ans == -1 || curVal < ans) {
      ans = curVal;
      X = i;
    } else if (ans == curVal) {
      X = min(X, i);
    }
  }
  cout << X << endl;
  return 0;
}
