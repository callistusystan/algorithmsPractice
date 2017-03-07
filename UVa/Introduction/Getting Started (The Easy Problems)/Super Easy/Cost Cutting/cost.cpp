#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    vector<int> salaries(3);
    cin >> salaries[0] >> salaries[1] >> salaries[2];

    sort(salaries.begin(), salaries.end());
    printf("Case %d: %d\n", t, salaries[1]);
  }
  return 0;
}
