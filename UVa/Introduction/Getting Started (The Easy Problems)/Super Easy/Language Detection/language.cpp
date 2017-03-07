#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  int t=1;
  while (cin >> line && line.compare("#") != 0) {
    cout << "Case " << t << ": ";
    if (line == "HELLO") cout << "ENGLISH";
    else if (line == "HOLA") cout << "SPANISH";
    else if (line == "HALLO") cout << "GERMAN";
    else if (line == "BONJOUR") cout << "FRENCH";
    else if (line == "CIAO") cout << "ITALIAN";
    else if (line == "ZDRAVSTVUJTE") cout << "RUSSIAN";
    else cout << "UNKNOWN";
    cout << endl;
    t++;
  }
  return 0;
}
