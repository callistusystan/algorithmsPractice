// https://www.hackerrank.com/challenges/library-fine

#include <bits/stdc++.h>

using namespace std;

int main() {
  int DR, MR, YR, DE, ME, YE;

  cin >> DR >> MR >> YR >> DE >> ME >> YE;

  if (YR < YE)
    cout << 0;
  else if (YR == YE) {
    if (MR < ME)
      cout << 0;
    else if (MR == ME) {
      if (DR < DE)
        cout << 0;
      else if (DR == DE)
        cout << 0;
      else
        cout << 15*(DR-DE);
    } else
      cout << 500*(MR - ME);
  } else
    cout << 10000;

  cout << endl;
  return 0;
}
