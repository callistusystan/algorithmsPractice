#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int K;
    cin >> K;
    vector<int> costs(256,0);
    for (int i=0;i<K;i++) {
      unsigned char c;
      int val;
      cin >> c >> val;
      costs[c] = val;
    }
    int M;
    cin >> M;
    cin.ignore();
    string line;
    int ans = 0;
    while (M--) {
      getline(cin, line);
      int L = line.size();
      for (int i=0;i<L;i++) {
        ans += costs[(unsigned char)line[i]];
      }
    }
    printf("%.2lf$\n", (double)ans/100);
  }
  return 0;
}
