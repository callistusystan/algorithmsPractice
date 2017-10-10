#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N; vector<ll> freq(1e5+5), memo(1e5+5, -1);

ll rec(int cur) {
  if (cur > 1e5) return 0;
  if (memo[cur] != -1) return memo[cur];

  // no choose
  ll ans = rec(cur+1);
  if (freq[cur] > 0) {
    ans = max(ans, (ll)freq[cur]*cur + rec(cur+2));
  }
  memo[cur] = ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N;

  for (int i=0;i<N;i++) {
    int num; cin >> num;
    freq[num]++;
  }

  cout << rec(1) << endl;

  return 0;
}
