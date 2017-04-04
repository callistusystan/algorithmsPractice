#include <bits/stdc++.h>

using namespace std;

vector<int> daysMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
int D,M,Y;

bool isLeapYear() {
  if (Y%4 == 0) {
    return ((Y%100 != 0) || (Y%400 == 0));
  }
  return false;
}

void increment() {
  D++;
  if (D > daysMonth[M-1]) {
    if (isLeapYear() && M == 2 && D == 29) return;
    D = 1;

    M++;
    if (M > 12) {
      M = 1;
      Y++;
    }
  }
}

bool inRange(int d1, int m1, int d2, int m2) {
  return ((M == m1 && D >= d1) || (M == m2 && D <= d2));
}

string getAns() {
  if (inRange(21,1,19,2)) return "aquarius";
  else if (inRange(20,2,20,3)) return "pisces";
  else if (inRange(21,3,20,4)) return "aries";
  else if (inRange(21,4,21,5)) return "taurus";
  else if (inRange(22,5,21,6)) return "gemini";
  else if (inRange(22,6,22,7)) return "cancer";
  else if (inRange(23,7,21,8)) return "leo";
  else if (inRange(22,8,23,9)) return "virgo";
  else if (inRange(24,9,23,10)) return "libra";
  else if (inRange(24,10,22,11)) return "scorpio";
  else if (inRange(23,11,23,12)) return "sagittarius";
  else return "capricorn";
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    scanf("%2d%2d%4d\n", &M,&D,&Y);
    for (int i=0;i<40*7;i++) increment();
    string ans = getAns();

    printf("%d %02d/%02d/%04d ", t, M, D, Y);
    cout << ans << endl;
  }
  return 0;
}
