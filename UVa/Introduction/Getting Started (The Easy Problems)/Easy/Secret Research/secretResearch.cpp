#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    string sequence;
    cin >> sequence;

    int N = sequence.size();

    if (sequence == "1" || sequence == "4" || sequence == "78")
      cout << "+";
    else if (sequence.substr(N-2, 2) == "35")
      cout << "-";
    else if (sequence[0] == '9' && sequence[N-1] == '4')
      cout << "*";
    else if (sequence.substr(0,3) == "190")
      cout << "?";
    else {
      cout << "+";
    }
    cout << endl;
  }
  return 0;
}
