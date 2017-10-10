#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<string> grid(55);

int N, M;
int dR[] = {-1,0,1,0};
int dC[] = {0,1,0,-1};

bool canGo(int i, int j) {
	if (i < 0 || i >= N || j < 0 || j >= M) return false;
	return true;
}

void dfs(int i, int j) {
	grid[i][j] = 'W';
	for (int k=0;k<4;k++) {
		int nextI, nextJ;
		nextI = i+dR[k]; nextJ = j+dC[k];
		if (canGo(nextI, nextJ) && (grid[nextI][nextJ] == 'C' || grid[nextI][nextJ] == 'L')) {
			dfs(nextI, nextJ);
		}
	}

}

int main() {
	cin >> N >> M;

	for (int i=0;i<N;i++) cin >> grid[i];

	int ans = 0;
	for (int i=0;i<N;i++) {
		for (int j=0;j<M;j++) {
			if (grid[i][j] == 'L') {
				dfs(i,j);
				ans++;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
