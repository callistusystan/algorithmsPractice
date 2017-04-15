#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    list<char> ans;
    list<char>::iterator it = ans.begin();
    for (char c: s) {
      if (c == '[') {
        it = ans.begin();
      } else if (c==']') {
        it = ans.end();
      } else {
        ans.insert(it, c);
      }
    }

    for (char c: ans) cout << c;
    cout << endl;
  }
  return 0;
}
