#include <bits/stdc++.h>

using namespace std;

map<string, map<string, string>> bend;

int main() {
  bend["+x"]["+y"] = "+y";
  bend["+x"]["-y"] = "-y";
  bend["+x"]["+z"] = "+z";
  bend["+x"]["-z"] = "-z";

  bend["-x"]["+y"] = "-y";
  bend["-x"]["-y"] = "+y";
  bend["-x"]["+z"] = "-z";
  bend["-x"]["-z"] = "+z";

  bend["+y"]["+y"] = "-x";
  bend["+y"]["-y"] = "+x";
  bend["+y"]["+z"] = "+y";
  bend["+y"]["-z"] = "+y";

  bend["-y"]["+y"] = "+x";
  bend["-y"]["-y"] = "-x";
  bend["-y"]["+z"] = "-y";
  bend["-y"]["-z"] = "-y";

  bend["+z"]["+y"] = "+z";
  bend["+z"]["-y"] = "+z";
  bend["+z"]["+z"] = "-x";
  bend["+z"]["-z"] = "+x";

  bend["-z"]["+y"] = "-z";
  bend["-z"]["-y"] = "-z";
  bend["-z"]["+z"] = "+x";
  bend["-z"]["-z"] = "-x";
  int L;
  while (cin >> L, L) {
    string decision, pos="+x";
    for (int i=0;i<L-1;i++) {
      cin >> decision;
      if (decision != "No") {
        pos = bend[pos][decision];
      }
    }

    cout << pos << endl;
  }
  return 0;
}
