#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    string word;
    cin >> word;

    if (word.length() == 5) {
      cout << 3;
    } else {
      int cmp1=0;

      if (word[0] == 'o') cmp1++;
      if (word[1] == 'n') cmp1++;
      if (word[2] == 'e') cmp1++;

      cout << ((cmp1 >= 2) ? 1 : 2);
    }
    cout << endl;
  }
  return 0;
}
