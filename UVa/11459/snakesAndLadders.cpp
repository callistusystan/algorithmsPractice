#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a,b,c;
		cin >> a >> b >> c;

		vector<int> goTo(101), playerPos(a,1);
		for (int i=0;i<101;i++) {
			goTo[i] = i;
		}

		for (int i=0;i<b;i++) {
			int pos1, pos2;
			cin >> pos1 >> pos2;
			goTo[pos1] = pos2;
		}

		bool gameEnd = false;

		for (int i=0;i<c;i++) {
			int number;
			cin >> number;

			if (!gameEnd) {
				playerPos[i%a] += number;
				if (playerPos[i%a] > 100) playerPos[i%a] = 100;
				while (goTo[playerPos[i%a]] != playerPos[i%a]) {
					playerPos[i%a] = goTo[playerPos[i%a]];
				}

				if (playerPos[i%a] == 100) {
					gameEnd = true;
				}
			}
		}

		for (int i=0;i<a;i++)
			cout << "Position of player " << i+1 << " is " << playerPos[i] << "." << endl;
	}
	return 0;
}
