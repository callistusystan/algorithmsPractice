#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
ll S;
vector<ll> a;

pair<bool, ll> f(ll K) {
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i=0;i<N;i++) {
    pq.push(a[i]+(i+1)*K);
  }

  ll cost =0;
  for (int i=0;i<K;i++) {
    cost += pq.top(); pq.pop();
  }

  return {S >= cost, cost};
}

int main() {
  cin >> N >> S;
  a.resize(N);

  for (int i=0;i<N;i++) cin >> a[i];

  ll lo = 0, hi = N+1;
  ll cost = 0;
  while (lo != hi -1) {
    ll mid = lo+(hi-lo)/2;
    pair<bool, ll> result = f(mid);
    if (result.first) {
      lo = mid;
      cost = result.second;
    }
    else hi = mid;
  }

  cout << lo << " " << cost << endl;
  return 0;
}
