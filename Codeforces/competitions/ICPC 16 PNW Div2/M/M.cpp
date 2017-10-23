#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N, GO_UP = 0, GO_DOWN = 1;
vi A(55);
vector<vi> memo(55, vi(2,-1));

int rec(int id, int action) {
	if (id == N) return 0;
	if (memo[id][action] != -1) return memo[id][action];

	int ans = 1;
	for (int i=id+1;i<N;i++) {
		if (action == GO_UP && A[i] > A[id]) ans = max(ans, 1+ rec(i, GO_DOWN));
		else if (action == GO_DOWN && A[i] < A[id]) ans = max(ans, 1+ rec(i, GO_UP));
	}

	return memo[id][action] = ans;
}

int main() {

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> A[i];
	}

	int ans = 1;
	for (int i=0;i<N;i++) {
		ans = max(ans, rec(i, GO_UP));
		ans = max(ans, rec(i, GO_DOWN));
	}

	cout << ans << endl;

	return 0;
}
