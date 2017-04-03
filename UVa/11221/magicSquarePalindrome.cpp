#include <bits/stdc++.h>

using namespace std;

int main() {
     int T;
     cin >> T;
     ws(cin);
     for (int t=1;t<=T;t++) {
          cout << "Case #" << t << ":" << endl;
          string line;
          getline(cin, line);
          vector<char> letters;
          for (char c : line) {
               if (isalpha(c)) letters.push_back(c);
          }

          int N = letters.size();
          int K = sqrt(N);

          if (K*K != N) {
               cout << "No magic :(" << endl;
               continue;
          }
          vector<vector<char>> magicSquare(K, vector<char>(K));
          for (int i =0;i<N;i++) {
               magicSquare[i/K][i%K] = letters[i];
          }
          bool valid = true;

          // method 1
          int index = 0;
          for (int i=0;i<K;i++) {
               for (int j=0;j<K;j++) {
                    if (magicSquare[i][j] != letters[index]) valid = false;
                    index++;
               }
          }
          // method 2
          index = 0;
          for (int j=0;j<K;j++) {
               for (int i=0;i<K;i++) {
                    if (magicSquare[i][j] != letters[index]) valid = false;
                    index++;
               }
          }
          // method 3
          index = 0;
          for (int i=K-1;i>=0;i--) {
               for (int j=K-1;j>=0;j--) {
                    if (magicSquare[i][j] != letters[index]) valid = false;
                    index++;
               }
          }
          // method 4
          index = 0;
          for (int j=K-1;j>=0;j--) {
               for (int i=K-1;i>=0;i--) {
                    if (magicSquare[i][j] != letters[index]) valid = false;
                    index++;
               }
          }

          if (valid) cout << K << endl;
          else cout << "No magic :(" << endl;
     }
     return 0;
}
