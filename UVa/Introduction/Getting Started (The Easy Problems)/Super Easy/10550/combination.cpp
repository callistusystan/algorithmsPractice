#include <bits/stdc++.h>

using namespace std;

int degrees(int num) {
  return num*9;
}

int main() {
  int pos, num1, num2, num3;
  while (cin >> pos >> num1 >> num2 >> num3, pos || num1 || num2 || num3) {
    int totalDegrees;
    totalDegrees = 720;
    totalDegrees += (pos > num1) ? degrees(pos-num1) : degrees(pos-num1+40);
    totalDegrees += 360;
    totalDegrees += (num2 > num1) ? degrees(num2-num1) : degrees(num2-num1+40);
    totalDegrees += (num2 > num3) ? degrees(num2-num3) : degrees(num2-num3+40);
    cout << totalDegrees << endl;
  }
  return 0;
}
