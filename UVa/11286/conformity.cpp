#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N, N) {
    map<vector<int>, int> myMap;
    vector<vector<int>> choices(N, vector<int>(5));
    int most = 1;
    for (int i=0;i<N;i++) {
      for (int j=0;j<5;j++) {
        cin >> choices[i][j];
      }
      sort(choices[i].begin(), choices[i].end());
      myMap[choices[i]]++;
      most = max(most, myMap[choices[i]]);
    }

    int ans = 0;
    for (int i=0;i<N;i++) {
      if (myMap[choices[i]] == most)
        ans++;
    }

    cout << ans << endl;
  }
  return 0;
}
