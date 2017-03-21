#include <bits/stdc++.h>

using namespace std;

int main() {
  int t= 1;
  string word;
  while (cin >> word, word != "*") {
    cout << "Case " << t << ": ";
    if (word == "Hajj")
      cout << "Hajj-e-Akbar";
    else
      cout << "Hajj-e-Asghar";

    cout << endl;
    t++;
  }
  return 0;
}
