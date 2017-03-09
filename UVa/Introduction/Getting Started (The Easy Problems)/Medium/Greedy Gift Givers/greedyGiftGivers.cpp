#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  map<string, int> namesIndex;
  bool first = true;
  while (cin >> N) {
    if (first) first = false;
    else cout << endl;
    vector<string> names(15);
    for (int i=0;i<N;i++) {
      cin >> names[i];
      namesIndex[names[i]] = i;
    }

    vector<int> amountSpent(N), amountGained(N, 0);
    for (int i=0;i<N;i++) {
      string giver;
      int money;
      cin >> giver >> money;

      int nPeople;
      cin >> nPeople;

      if (nPeople) {
        amountSpent[namesIndex[giver]] = (money/nPeople)*nPeople;

        for (int j=0;j<nPeople;j++) {
          string receiver;
          cin >> receiver;
          amountGained[namesIndex[receiver]] += money/nPeople;
        }
      }
    }

    for (int i=0;i<N;i++) {
      cout << names[i] << " " << (-amountSpent[i] + amountGained[i]) << endl;
    }
  }
  return 0;
}
