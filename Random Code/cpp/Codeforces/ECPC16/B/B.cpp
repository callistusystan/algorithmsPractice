#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int N,M; cin >> N >> M;

  vector<vi> floor(105);

  for (int i=0;i<M;i++) {
    int ki,fi; cin >> ki >> fi;
    floor[fi].push_back(ki);
  }

  for (int i=0;i<105;i++) {
    sort(floor[i].begin(), floor[i].end());
  }

  vi possible;
  for (int i=1;i<105;i++) {
    // assume i flat per floor
    bool canDo = true;
    for (int j=1;j<105;j++) {
      if (floor[j].empty()) continue;
      int firstFlat = i*(j-1)+1;
      int lastFlat = i*(j);
      if (!(firstFlat <= floor[j][0] && floor[j].back() <= lastFlat)) {
        canDo = false;
        break;
      }
    }
    if (canDo) {
      possible.push_back(i);
      if (possible.size() > 1) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  if (possible.size() == 1) {
    N--;
    cout << N/possible[0]+1 << endl;
  }
  else cout << -1 << endl;

  return 0;
}
