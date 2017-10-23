#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int L[3], W[3];

bool solve() {
	int area = 0;
	for (int i=0;i<3;i++) {
		cin >> L[i] >> W[i];
		area += L[i]*W[i];
	}

	int side; bool isSquare = false;
	for (side=sqrt(area)-1;side<=sqrt(area)+1;side++) {
		if (side <= 0) continue;
		if (side*side == area) {
			isSquare = true;
			break;
		}
	}

	if (!isSquare) return false;

	// identify rect with L/W == side
	int remainingSide = -1, rectA = -1;
	for (int i=0;i<3;i++) {
		if (L[i] == side || W[i] == side) {
			rectA = i;
			if (L[i] != side) remainingSide = side - L[i];
			else remainingSide = side - W[i];
		}
	}

	if (rectA == -1) return false;

	swap(L[rectA], L[2]);
	swap(W[rectA], W[2]);

	if ((L[0] == side || W[0] == side) && (L[1] == side || W[1] == side)) return true;
	if ((L[0] == remainingSide || W[0] == remainingSide) && (L[1] == remainingSide || W[1] == remainingSide)) return true;

	return false;
}

int main() {
	if (solve()) cout << "YES";
	else cout << "NO";
	cout << endl;
	return 0;
}
