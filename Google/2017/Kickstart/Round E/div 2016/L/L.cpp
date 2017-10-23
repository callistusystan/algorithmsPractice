#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

#define NONE -1
#define LEFT 0
#define RIGHT 1

int L, R, N, C, M;

vi color(2005, NONE);
vvi adjList(2005);
vvi components;

bool dp(int id, int sumToMake, vvi &memo) {
	if (sumToMake == 0) return true;
	if (id == M || sumToMake < 0) return false;
	if (memo[id][sumToMake] != -1) return memo[id][sumToMake];
	bool ans = false;

	int curCompRemain = abs(components[id][0]-components[id][1]);
	ans |= dp(id+1, sumToMake-curCompRemain, memo);
	ans |= dp(id+1, sumToMake, memo);

	memo[id][sumToMake] = ans;
	return ans;
}

pair<bool, vi> dfs(int u, int c) {
	pair<bool, vi> ans = { true , {0,0} };

	color[u] = c;
	ans.second[c]++;

	for (int v : adjList[u]) {
		if (color[v] == NONE) {
			auto result = dfs(v, 1-c);
			if (!result.first) return {false, {-1,-1}};
			ans.first &= result.first;
			ans.second[0] += result.second[0];
			ans.second[1] += result.second[1];
		} else if (color[v] == c) {
			return {false, {-1,-1}};
		}
	}

	return ans;
}

bool solve() {
	cin >> L >> R >> N >> C;
	if (L > R) {
		int tmp = L;
		L = R;
		R = tmp;
	}

	for (int i=0;i<C;i++) {
		int u,v; cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	if (N > L+R) return false;

	for (int u=0;u<N;u++) {
		if (color[u] != NONE) continue;
		pair<bool, vi> result = dfs(u, LEFT);
		if (!result.first) return false;

		components.push_back(result.second);
	}
	M = components.size();

	// reduce problem by eliminating the minimum that has to be in both L and R

	// work with remaining N in each component that needs to be allocated to L or R
	int remainN = 0;
	for (vi cur : components) {
		int minN = min(cur[0],cur[1]);
		L -= minN; R -= minN;
		remainN += abs(cur[0]-cur[1]);
	}

	if (L<0 || R < 0) return false;

	// TODO: WHY DOES THIS FAIL WHEN I DO vvi memo(M+5, vi(L+5, -1));
	vvi memo(M+5, vi(L+5, -1));
	// see if we can make a sum of i using components
	for (int i=0;i<= L;i++) {
		if (i <= L && (remainN-i) <= R && dp(0, i, memo)) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << (solve() ? "Yes" : "No") << endl;
	return 0;
}
