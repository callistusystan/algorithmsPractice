#include <bits/stdc++.h>

using namespace std;

#define first X
#define second Y

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int MEX(set<int> g){
	int ans = 0;
	while (g.count(ans) != 0) ans++;
	return ans;
}

void solve_naive() {
	// grundy numbers
	int B,N;
	B = 6; N = 100;

	vi G(N+5);
	G[0] = 0;
	for (int i=1;i<N;i++) {
		// loop possible moves
		int e = 0;
		set<int> grundyNumbers;
		while (i - pow(B,e) >= 0) {
			grundyNumbers.insert(G[i-pow(B,e)]);
			e++;
		}
		G[i] = MEX(grundyNumbers);
	}

	for (int i=0;i<N;i++) {
		cerr << G[i] << " \n"[i==N-1];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#ifdef ONLINE_JUDGE
	#define name "powers"
		freopen(name ".in", "r", stdin);
	#endif

	// solve_naive();
	int T; cin >> T;
	while (T--) {
		int G; cin >> G;
		vi games(G);
		for (int i=0;i<G;i++) {
			ll B,N; cin >> B >> N;
			if (B%2 == 1) {
				games[i] = N%2;
			} else {
				ll k = N%(B+1);
				if (k == B) {
					games[i] = 2;
				} else {
					games[i] = k%2;
				}
			}
		}
		ll ans = 0;
		for (int i=0;i<G;i++) {
			ans ^= games[i];
		}
		if (ans == 0) cout << 2 << '\n';
		else cout << 1 << '\n';

	}
	return 0;
}

/*
B = 4
can go to N-1,N-4,N-16..
       PNPNN PNPNN PNPNN PNPNN PNPNN
Grundy 01012 01012

B = 2
PNN PNN PNN PNN PNN

*/
