#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    map<int, int> myMap;

    int ans = 0, startFrom = 0;
    for (int i=0;i<N;i++) {
      int id;
      cin >> id;
      if (myMap.count(id)){
        startFrom = max(startFrom, myMap[id]+1);
      }
      ans = max(ans, i-startFrom+1);
      myMap[id] = i;
    }

    cout << ans << endl;
  }
  return 0;
}
