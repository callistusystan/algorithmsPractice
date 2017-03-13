#include <bits/stdc++.h>

using namespace std;

vector<bool> given(55);
vector<int> princess(3);
vector<int> prince(2);

bool princeWin() {
  int count = 0;
  for (int i=0;i<3;i++) {
    if (prince[i] > princess[i]) count++;
  }
  return count >=2;
}

bool canPrinceAlwaysWin() {
  sort(princess.begin(), princess.end());
  do {
    if (!princeWin()) return false;
  } while (next_permutation(princess.begin(), princess.end()));
  return true;
}

int main() {
  int A,B,C,X,Y;
  while (cin >> A >> B >> C >> X >> Y, A || B || C || X || Y) {
    fill(given.begin(), given.end(), false);
    given[A] = true; given[B] = true; given[C] = true; given[X] = true; given[Y] = true;

    princess[0]=A;princess[1]=B;princess[2]=C;
    prince[0]=X;prince[1]=Y;

    bool possible = false;
    for (int i=1;i<=52;i++) {
      if (!given[i]) {
        prince[2] = i;
        if (canPrinceAlwaysWin()) {
          possible = true;
          break;
        }
      }
    }

    if (possible) {
      cout << prince[2];
    } else cout << "-1";

    cout << endl;
  }
  return 0;
}
