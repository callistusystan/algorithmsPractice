#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

bool isSymbol(char c) {
  return c == '@' || c == '?' || c == '!';
}

vector<vi> adjList(7);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;
  while (N--) {
    string s; cin >> s;

    int nLetters = 0, nDigits = 0, nSymbols = 0;

    for (char c : s) {
      if (isalpha(c)) nLetters++;
      else if (isdigit(c)) nDigits++;
      else if (isSymbol(c)) nSymbols++;
    }

    cout << "The last character ";
    if (nLetters >= 4 && nDigits >= 4 && nSymbols >= 2) {
      cout << "can be any type.";
    } else if (nLetters >= 4 && nDigits >= 4) {
      cout << "must be a symbol.";
    } else if (nLetters >= 4 && nSymbols >= 2) {
      cout << "must be a digit.";
    } else if (nDigits >= 4 && nSymbols >= 2) {
      cout << "must be a letter.";
    }
    cout << endl;
  }
  return 0;
}
