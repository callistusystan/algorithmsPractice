#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N, K;

int main() {
	cin >> N >> K;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	ll ans, tElapsed;
	ans = tElapsed = 0;
	for (int i=0;i<N;i++) {
		ll t_i; cin >> t_i;
		pq.push(t_i);

		if ((int)pq.size() == K) {
			ll t = pq.top(); pq.pop();
			tElapsed += t;
			ans += tElapsed;
		}
	}

	while (!pq.empty()) {
		ll t = pq.top(); pq.pop();
		tElapsed += t;
		ans += tElapsed;
	}

	cout << ans << endl;

	return 0;
}
