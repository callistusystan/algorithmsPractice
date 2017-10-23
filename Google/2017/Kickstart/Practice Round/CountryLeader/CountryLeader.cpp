#include <bits/stdc++.h>

using namespace std;

int getUniqueChars(string name) {
	int unique_count = 0;
	vector<bool> hasAppeared(26, false);

	for (int i =0; i<name.size(); i++) {
		if ( ( isalpha(name[i]) ) && ( !hasAppeared[name[i] - 'A'] ) ){
			unique_count++;
			hasAppeared[name[i] - 'A'] = true;
    }
}
return unique_count;
}

int main() {
	int T, N;
	cin >> T;

	for (int t = 0;t < T;t++) {
		cin >> N;
		string bestName, curName;
		int bestNameUniqueChars = -1;
		for (int i = 0;i < N;i++) {
            ws(cin);
            getline(cin, curName);
			int curNameUniqueChars = getUniqueChars(curName);
			if (curNameUniqueChars > bestNameUniqueChars) {
				bestName = curName;
				bestNameUniqueChars = curNameUniqueChars;
			} else if (curNameUniqueChars == bestNameUniqueChars) {
				if (curName.compare(bestName) < 0) {
					bestName = curName;
				}
			}

		}
		cout << "Case #" << t+1 << ": " << bestName << endl;
	}
	return 0;
}
