#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/grading

int main() {
  int N;
  cin >> N;
  for (int i=0;i<N;i++) {
    int grade;
    cin >> grade;
    if (grade >= 38) {
      int lastDigit = grade%10;
      if (lastDigit == 3 || lastDigit == 4)
        grade = grade - grade%10 + 5;
      else if (lastDigit == 8 || lastDigit == 9)
        grade = grade - grade%10 + 10;
    }
    cout << grade << endl;
  }
  return 0;
}
