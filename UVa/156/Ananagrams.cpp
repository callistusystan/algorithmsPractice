#include <bits/stdc++.h>

using namespace std;

int main() {
     string word;
     vector<string> words;
     map<string, int> myMap;
     while (cin >> word, word != "#") {
          words.push_back(word);
          string lowerWord;
          for (char c : word) lowerWord.push_back(tolower(c));
          sort(lowerWord.begin(), lowerWord.end());
          myMap[lowerWord]++;
     }
     sort(words.begin(), words.end());
     for (string word : words) {
          string lowerWord;
          for (char c : word) lowerWord.push_back(tolower(c));
          sort(lowerWord.begin(), lowerWord.end());
          if (myMap[lowerWord] == 1)
               cout << word << endl;
     }
     return 0;
}
