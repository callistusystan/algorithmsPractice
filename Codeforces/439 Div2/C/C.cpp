#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll R;
vi N(3), P(3), QUANTITY(3);

bool f(ll n) {
  ll cost = 0;
  for (int i=0;i<3;i++) {
    // buy ingredients if not enough to make n
    if (N[i] < QUANTITY[i]*n)
      cost += (QUANTITY[i]*n-N[i])*P[i];
  }
  // see if we have enough $$
  return R >= cost;
}

int main() {
  string s; cin >> s;
  QUANTITY[0] = count(s.begin(), s.end(), 'B');
  QUANTITY[1] = count(s.begin(), s.end(), 'S');
  QUANTITY[2] = count(s.begin(), s.end(), 'C');
  for (int i=0;i<3;i++) cin >> N[i];
  for (int i=0;i<3;i++) cin >> P[i];
  cin >> R;

  ll lo = 0, hi = 1e12+500;
  while (lo != hi -1) {
    ll mid = lo+(hi-lo)/2;
    if (f(mid)) lo = mid;
    else hi = mid;
  }

  cout << lo << endl;
  return 0;
}
