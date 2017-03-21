#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n, n > -1) {
  cout << "Round " << n << endl;
  string word, guessedLetters;
  cin >> word >> guessedLetters;

  vector<bool> inWord(26,false), hasGuessed(26, false);

  int nUnique = 0;
  for (char c : word) {
    int index = c-'a';
    if (!inWord[index]) {
      nUnique++;
    }
    inWord[index] = true;
    }

    int nStrokes = 0;
    bool gameFinished = false;
    for (char c : guessedLetters) {
      int index = c-'a';
      if (!hasGuessed[index]) {
        if (inWord[index]) {
          nUnique--;
          if (nUnique == 0) {
            cout << "You win.";
            gameFinished = true;
            break;
          }
        } else {
          nStrokes++;
          if (nStrokes == 7) {
            cout << "You lose.";
            gameFinished = true;
            break;
          }
        }
      }
      hasGuessed[index] = true;
    }
    if (!gameFinished) cout << "You chickened out.";
      cout << endl;
  }
return 0;
}
