#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board(5,vector<int>(5));

void markN(int n) {
  for (int i=0;i<5;i++)
    for (int j=0;j<5;j++)
      if (board[i][j] == n)
        board[i][j] = -1;
}

int countLines() {
  int nLines = 0;
  // rows
  for (int i=0;i<5;i++) {
    nLines += (count(board[i].begin(), board[i].end(), -1) == 5) ? 1 : 0;
  }

  // columns
  for (int j=0;j<5;j++) {
    int countMarked = 0;
    for (int i=0;i<5;i++) {
      if (board[i][j] == -1)
        countMarked++;
    }

    if (countMarked == 5)
      nLines++;
  }

  int countMarked1, countMarked2;
  countMarked1 = countMarked2 = 0;
  for (int i=0;i<5;i++) {
    if (board[i][i] == -1)
      countMarked1++;
    if (board[i][4-i] == -1)
      countMarked2++;
  }

  if (countMarked1 == 5) nLines++;
  if (countMarked2 == 5) nLines++;

  return nLines;
}

int main() {
  int T;
  cin >> T;
  for (int t=0;t<T;t++) {
    for (int i=0;i<5;i++)
      for (int j=0;j<5;j++) {
        if (i==2 && j==2)
          board[i][j] = -1;
        else
          cin >> board[i][j];
      }

    vector<int> numbers(75);

    for (int i=0;i<75;i++) {
      cin >> numbers[i];
    }

    for (int i=0;i<75;i++) {
      markN(numbers[i]);

      if (countLines() >= 1) {
        cout << "BINGO after " << i+1 << " numbers announced" << endl;
        break;
      }
    }


  }
  return 0;
}
