#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    string num;
    cin >> num;

    int N = num.size();

    // find i where first violation
    bool violation = false;
    int i;
    for (i=0;i<=N-2;i++) {
      if (num[i+1] < num[i]) {
        violation = true;
        break;
      }
    }

    if (violation) {
      // check if decrementing num[i] violates previous
      // find i where decrementing num[i] will not violate previous

      num[i] = num[i]-1;
      while (i > 0 && num[i] < num[i-1]) {
        i--;
        num[i] = num[i]-1;
      }

      // from that i to the end, change to 9

      for (i=i+1;i<N;i++) {
        num[i] = '9';
      }
    }

    cout << "Case #" << t << ": " << ((num[0] == '0') ? num.substr(1) : num) << endl;
  }
  return 0;
}
