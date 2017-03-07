#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, B, H, W;
  vector<int> hotelPrices(25);
  vector<vector<int>> hotelBeds(25, vector<int>(20));
  while (cin >> N >> B >> H >> W) {
    int minCost = INT_MAX/2;
    for (int h=0;h<H;h++) {
      cin >> hotelPrices[h];

      // see if cost less than budget
      int curHotelCost = N*hotelPrices[h];

      // see if enough bed for N people;
      bool enoughBeds = false;
      for (int w=0;w<W;w++) {
        cin >> hotelBeds[h][w];
        if (hotelBeds[h][w] >= N) {
          enoughBeds = true;
        }
      }

      if (curHotelCost < B && enoughBeds)
        minCost = min(minCost, curHotelCost);
    }

    if (minCost == INT_MAX/2) {
      cout << "stay home";
    } else {
      cout << minCost;
    }
    cout << endl;
  }
  return 0;
}
