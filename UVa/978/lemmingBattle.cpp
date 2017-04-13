#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int B, SG, SB;
    cin >> B >> SG >> SB;
    multiset<int> green, blue;
    for (int i=0;i<SG;i++) {
      int power;
      cin >> power;
      green.insert(power);
    }
    for (int i=0;i<SB;i++) {
      int power;
      cin >> power;
      blue.insert(power);
    }

    while (!green.empty() && !blue.empty()) {
      // fill battlefields
      int nBF = min(B, (int)min(green.size(), blue.size()));
      vector<vector<int>> battlefields(nBF, vector<int>(2));
      for (int i=0;i<nBF;i++) {
        auto itergs = green.end(), iterbs = blue.end();
        itergs--; iterbs--;
        int gs = *itergs, bs = *iterbs;
        battlefields[i][0] = gs; battlefields[i][1] = bs;
        green.erase(itergs); blue.erase(iterbs);
      }

      // let them fight, and put them back to sets
      for (int i=0;i<nBF;i++) {
        int gs,bs;
        gs = battlefields[i][0]; bs = battlefields[i][1];
        if (gs > bs) {
          gs -= bs;
          green.insert(gs);
        } else if (bs > gs) {
          bs -= gs;
          blue.insert(bs);
        }
      }
    }

    if (green.empty() && blue.empty()) {
      cout << "green and blue died" << endl;
    } else if (green.size()) {
      cout << "green wins" << endl;
      for (auto rit = green.rbegin();rit != green.rend();rit++) {
        cout << *rit << endl;
      }
    } else if (blue.size()) {
      cout << "blue wins" << endl;
      for (auto rit = blue.rbegin();rit != blue.rend();rit++) {
        cout << *rit << endl;
      }
    }
    if (T) cout << endl;
  }
  return 0;
}
