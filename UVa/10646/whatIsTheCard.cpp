#include <bits/stdc++.h>

using namespace std;

const string ranks = "__23456789TJQKA";
const string suits = "SHDC";
vector<string> deck(55);


int getRankIndex(string card) {
  char rank = card[0];
  return ranks.find(rank);
}

int getSuitIndex(string card) {
  char suit = card[1];
  return suits.find(suit);
}

int getValue(string card) {
  if (getRankIndex(card) <=9) return getRankIndex(card);
  return 10;
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    int X, Y=0;

    for (int i=0;i<52;i++) {
      cin >> deck[i];
    }

    int pos = 26;
    for (int i=0;i<3;i++) {
      X = getValue(deck[pos]);
      pos--;
      pos -= (10-X);
      Y += X;
    }
    pos++;
    Y--;

    string ans;
    if (Y < pos) ans = deck[Y];
    else ans = deck[27 + Y-pos];

    cout << "Case " << t << ": " << ans << endl;
  }
  return 0;
}
