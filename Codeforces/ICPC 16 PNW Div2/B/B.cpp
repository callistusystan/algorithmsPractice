#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N,M;
set<ll> ans, realAns;
vi barbells(15), weights(15);

void rec(int id, ll left, ll right) {
	if (id == M) {
		if (left == right) ans.insert(left+right);
		return;
	}

	rec(id+1,left,right);
	rec(id+1, left+weights[id], right);
	rec(id+1, left, right+weights[id]);
}

int main() {
	cin >> N >> M;
	for (int i=0;i<N;i++) cin >> barbells[i];
	for (int i=0;i<M;i++) cin >> weights[i];

	rec(0, 0, 0);

	for (int i=0;i<N;i++) {
		for (auto it=ans.begin();it != ans.end();it++) {
			realAns.insert(barbells[i] + *it);
		}
	}


	for (auto it=realAns.begin();it != realAns.end();it++) {
		cout << *it << endl;
	}

	return 0;
}
