#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string line;

    ws(cin);
    getline(cin, line);
    istringstream istream(line);

    int mCount=0, fCount=0;
    string s;
    while (istream >> s) {
      if (s[0] == 'M') mCount++;
      else fCount++;

      if (s[1] == 'M') mCount++;
      else fCount++;
    }

    if (mCount != fCount || (mCount == 1 && fCount == 1))
      cout << "NO LOOP";
    else
      cout << "LOOP";
    cout << endl;
  }
  return 0;
}
