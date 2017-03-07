#include <bits/stdc++.h>

using namespace std;

int main() {
  int t = 1;
  int N;
  while (cin >> N, N) {
    int num1=0, num2=0;
    for (int i=0;i<N;i++) {
      int val;
      cin >> val;
      if (val == 0) num2++;
      else num1++;
    }
    printf("Case %d: %d\n", t++, num1-num2);
  }
  return 0;
}
