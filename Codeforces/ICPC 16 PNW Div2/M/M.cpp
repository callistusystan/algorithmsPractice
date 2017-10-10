#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
vi A(55);
vector<vi> memo(55, vi(2,1));

int main() {

	cin >> N;

	for (int i=0;i<N;i++) {
		cin >> A[i];
	}

	memo[0][0] = memo[0][1] = 1;

	// 0 means end in increase
	// 1 means end in decrease

	for (int i=1;i<N;i++) {
		for (int j=0;j<i;j++) {
			if (A[i] > A[j]) memo[i][0] = max(memo[i][0], memo[j][1] + 1);
			else if (A[i] < A[j]) memo[i][1] = max(memo[i][1], memo[j][0] + 1);
		}
	}

	cout << max(memo[N-1][0], memo[N-1][1]) << endl;

	return 0;
}
