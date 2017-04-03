#include <bits/stdc++.h>

using namespace std;

int main() {
     string line;
     while (getline(cin, line), line != "DONE") {
          vector<char> letters;
          for (char c : line) {
               if (isalpha(c)){
                    letters.push_back(tolower(c));
                  }
          }
          int N = letters.size();
          bool isPalind = true;
          for (int i =0;i<N;i++) {
               int j = N-1-i;
               if (letters[i] != letters[j]) {
                    isPalind = false;
                    break;
               }
          }
          if (isPalind) cout << "You won't be eaten!" << endl;
          else cout << "Uh oh.." << endl;
     }
     return 0;
}
