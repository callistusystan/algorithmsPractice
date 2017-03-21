#include <bits/stdc++.h>

using namespace std;

void increment(vector<vector<int>> &hintArray, int i, int j) {
	if ((i >= 0 && i < (int)hintArray.size()) && (j >= 0 && j < (int)hintArray[0].size())) {
		hintArray[i][j]++;
  }
}

int main() {
	int n,m,t=1;
	while (cin >> n >> m, n || m) {
    if (t > 1) cout << endl;
		vector<vector<char>> gameState(n,vector<char>(m));
		vector<vector<int>> hintArray(n, vector<int>(m, 0));
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				cin >> gameState[i][j];
        if (gameState[i][j] == '*') {
  				for (int k=i-1;k<=i+1;k++) {
  					for (int l=j-1;l <=j+1;l++) {
  				   increment(hintArray, k, l);
  					}
  				}
        }
			}
		}

		cout << "Field #" << t << ":" << endl;
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) {
				if (gameState[i][j] == '*') cout << '*';
				else cout << hintArray[i][j];
			}
			cout << endl;
		}
		t++;
	}
	return 0;
}
