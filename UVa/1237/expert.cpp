#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int N; cin >> N;
  vector<tuple<string, int, int>> carMakers;
  for (int i=0;i<N;i++) {
    string maker;
    int lo, hi;
    cin >> maker >> lo >> hi;
    carMakers.push_back(make_tuple(maker, lo, hi));
  }
  int Q; cin >> Q;
  while (Q--) {
    int P; cin >> P;
    int matches = 0;
    string lastMatch;
    for (tuple<string, int, int> carMaker : carMakers) {
      if (get<1>(carMaker) <= P && P <= get<2>(carMaker)) {
        matches++;
        lastMatch = get<0>(carMaker);
      }
    }
    if (matches == 1) cout << lastMatch;
    else cout << "UNDETERMINED";
    cout << endl;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
    if (T) cout << endl;
  }
  return 0;
}
