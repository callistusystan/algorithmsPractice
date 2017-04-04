#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  string line;
  getline(cin, line);
  getline(cin, line);
  while (T--) {
    map<string, int> treeCount;
    int n = 0;
    while (getline(cin, line) && line != "") {
      treeCount[line]++;
      n++;
    }
    for (pair<string, int> data : treeCount) {
      cout << data.first << " ";
      printf("%0.4lf\n",(100.0*data.second)/n);
    }

    if (T) cout << endl;
  }
  return 0;
}
