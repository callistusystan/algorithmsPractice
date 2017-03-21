#include <bits/stdc++.h>

using namespace std;

int charToScore(char c) {
  return c -'a' + 1;
}

int sumOfDigits(int n) {
  int s =0;
  while (n > 0) {
    s += n%10;
    n/=10;
  }
  return s;
}

int getSum(string name) {
  int s = 0;
  for (int i=0;i<(int)name.size();i++) {
    if (isalpha(name[i])) {
      char c = tolower(name[i]);
      s += charToScore(c);
    }
  }
  while (s >= 10) {
    s = sumOfDigits(s);
  }

  return s;
}

int main() {
  string name1, name2;
  while (getline(cin, name1)) {
    getline(cin, name2);

    int s1 = getSum(name1), s2 = getSum(name2);
    if (s1 == s2) {
      cout << "100.00 %";
    } else {
      printf("%.2lf %%", 100.0*(double)min(s1,s2)/max(s1,s2));
    }
    cout << endl;
  }
  return 0;
}
