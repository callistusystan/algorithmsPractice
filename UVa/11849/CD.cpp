#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  while (cin >> N >> M, N || M) {
    set<int> jackCDs;

    while (N--) {
      int id;
      cin >> id;
      jackCDs.insert(id);
    }

    int ans = 0;
    while (M--) {
      int id;
      cin >> id;
      if (jackCDs.count(id)) {
        ans++;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
