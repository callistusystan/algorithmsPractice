#include <bits/stdc++.h>

using namespace std;

const string ranks = "__23456789TJQKA";
const string suits = "SHDC";

vector<vector<bool>> deck(4, vector<bool>(20));
vector<int> suitCount(4);
vector<bool> suitStopped(4);
int points, bonusPoints;

int getSuitIndex(char suit) {
  return suits.find(suit);
}

int getRankIndex(char rank) {
  return ranks.find(rank);
}

void processCard(string card) {
  char rank = card[0];
  int suitIndex = getSuitIndex(card[1]);
  int rankIndex = getRankIndex(card[0]);

  deck[suitIndex][rankIndex] = true;
  suitCount[suitIndex]++;

  // rule 1
  if (rank == 'A') points += 4;
  if (rank == 'K') points += 3;
  if (rank == 'Q') points += 2;
  if (rank == 'J') points++;
}

int main() {
  string card;
  while (cin >> card) {
    for (int i=0;i<4;i++)
      for (int j=0;j<20;j++) deck[i][j] = false;

    for (int i=0;i<4;i++) {
      suitCount[i] = 0;
      suitStopped[i] = false;
    }

    points = bonusPoints = 0;

    processCard(card);

    for (int i=0;i<12;i++) {
      cin >> card;
      processCard(card);
    }

    // rule 2,3,4
    for (int i=0;i<4;i++) {
      if (deck[i][getRankIndex('K')] && suitCount[i] == 1) points--;
      if (deck[i][getRankIndex('Q')] && suitCount[i] <= 2) points--;
      if (deck[i][getRankIndex('J')] && suitCount[i] <= 3) points--;
    }

    // rule 5,6,7
    for (int i=0;i<4;i++) {
      if (suitCount[i] == 2) bonusPoints++;
      if (suitCount[i] <= 1) bonusPoints+=2;
    }

    // check stopped
    for (int i=0;i<4;i++) {
      if (deck[i][getRankIndex('A')]) suitStopped[i] = true;
      if (deck[i][getRankIndex('K')] && suitCount[i] >= 2) suitStopped[i] = true;
      if (deck[i][getRankIndex('Q')] && suitCount[i] >= 3) suitStopped[i] = true;
    }

    //   sum of i*(H-i)*(W-i) for i from 1 to min(H,W)
    //  [sum of i^3] + (h*W*[sum of i^2]) - (w+h)*[sum of i]

    cerr << points << endl;
    cerr << bonusPoints << endl;

    if (points + bonusPoints < 14) cout << "PASS";
    else if (suitStopped[0] && suitStopped[1] && suitStopped[2] && suitStopped[3] && points >= 16)
      cout << "BID NO-TRUMP";
    else {
      int maxCount = suitCount[0], maxSuit = 0;
      for (int i=1;i<4;i++) {
        if (suitCount[i] > maxCount) {
          maxSuit = i;
          maxCount = suitCount[i];
        }
      }
      cout << "BID " << suits[maxSuit];
    }
    cout << endl;
  }
  return 0;
}
