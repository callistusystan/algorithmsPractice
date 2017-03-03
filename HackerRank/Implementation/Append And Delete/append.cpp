#include <bits/stdc++.h>
using namespace std;
#define SZ(x) (int)(x.size())

int main() {
  string s, t;
  int K;

  cin >> s >> t >> K;

  if (K >= SZ(s) + SZ(t))
    cout <<  "Yes";
  else {
    int commonLen = 0;
    int minStringLen = min(SZ(s), SZ(t));
    for (int i=0;i<minStringLen;i++) {
      if (s[i] == t[i])
        commonLen++;
      else
        break;
    }

    if ((SZ(s) + SZ(t) - 2*commonLen) > K)
      cout << "No";
    else if ((SZ(s) + SZ(t) - 2*commonLen)%2 == K%2)
      cout << "Yes";
    else
      cout << "No";
  }

  cout << endl;

  return 0;
}
