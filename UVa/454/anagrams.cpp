#include <bits/stdc++.h>

using namespace std;

string getKey(string &word) {
  string lowerWord;
  for (char c : word)
    if (isalpha(c))
      lowerWord.push_back(c);
  sort(lowerWord.begin(), lowerWord.end());
  return lowerWord;
}

int main() {
  int T;
  cin >> T;
  string word;
  getline(cin, word);
  getline(cin, word);
  while (T--) {
    vector<string> words;
    while (getline(cin, word), word != "") {
      words.push_back(word);
    }

    sort(words.begin(), words.end());
    unordered_set<string> appeared;

    int N = words.size();
    for (int i=0;i<N;i++) {
      for (int j=i+1;j<N;j++) {
        if (getKey(words[i]) == getKey(words[j]))
          cout << words[i] << " = " << words[j] << endl;
      }
    }

    if (T) cout << endl;
  }
  return 0;
}
