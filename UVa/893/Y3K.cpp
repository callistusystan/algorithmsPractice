#include <bits/stdc++.h>

using namespace std;

vector<int> nDaysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
int nD, nM, nY;

bool isLeapYear(int year) {
  if (year%4 == 0) {
    return (year%100 != 0 || year%400 == 0);
  }
  return false;
}

void increment() {
  nD++;
  if (nD > nDaysInMonth[nM-1]) {
    // if it is 29 feb of a leap year, keep it
    if (isLeapYear(nY) && nM == 2 && nD == 29) return;

    // else increment month
    nD = 1;
    nM++;

    // if month is greater than 12, new year
    if (nM > 12) {
      nM = 1;
      nY++;
    }
  }
}

void decrement() {
  nD--;
  // if nD == 0 decrement month
  if (nD == 0) {
    nM--;
    // if nM == 0 decrement year
    if (nM == 0) {
      nM = 12;
      nY--;
    }

    // set day
    if (isLeapYear(nY) && nM == 2) {
      nD = 29;
      return;
    }
    nD = nDaysInMonth[nM-1];
  }
}

bool doWeDecrement() {
  if (nM > 2) {
    return isLeapYear(nY+1);
  }
  return isLeapYear(nY);
}

int main() {
  int nPredict, D, M, Y;
  while (cin >> nPredict >> D >> M >> Y, nPredict || D || M || Y) {
    nD = D;
    nM = M;
    nY = Y;
    // try to increment date by year
    while (nPredict >= 365) {
      if (doWeDecrement()) {
        nY++;
        decrement();
      } else {
        nY++;
      }
      nPredict -= 365;
    }

    while(nPredict--) {
      increment();
    }

    printf("%d %d %d\n", nD, nM, nY);
  }
  return 0;
}
