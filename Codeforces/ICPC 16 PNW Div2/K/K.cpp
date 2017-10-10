#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi f(6), s(6);
int main() {
  for (int i = 0; i < 6; i++) cin >> f[i];
  for (int i = 0; i < 6; i++) cin >> s[i];
  int sum = 0, d = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (f[i] > s[j]) sum += 1;
      if (f[i] == s[j]) d += 1;
    }
  }
  cout << fixed << setprecision(5) << (double)sum/(36-d) << endl;
  return 0;
}
