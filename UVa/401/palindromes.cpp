#include <bits/stdc++.h>

using namespace std;

string chars, mirrorChars;

int main() {
     chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
     mirrorChars= "A___3__HIL_JM_O___2TUVWXY51SE_Z__8_";

     string s;
     while (cin >> s) {
          int N = s.size();
          // string is not palindrome and is not mirrored string
          // is palind and is not mirrored string
          // is not palind and is mirrored string
          // is palind and mirrored string

          bool isPalind, isMirror;
          isPalind = true;
          isMirror = true;

          //palindrome
          for (int i = 0; i<N; i++){
               int j = N-1-i;
               if (s[i] != s[j]){
                    isPalind = false;
                    break;
               }

          }
          //mirrored
          for (int i = 0;i<N;i++) {
               int j = N-1-i;
               // check if s[j] is mirror of s[i]
               size_t index = chars.find(s[i]);
               if (s[j] != mirrorChars[index]) {
                    isMirror = false;
                    break;
               }
          }

          cout << s;
          if (!isPalind && !isMirror) cout << " -- is not a palindrome.";
          else if (isPalind && !isMirror) cout << " -- is a regular palindrome.";
          else if (!isPalind && isMirror) cout << " -- is a mirrored string.";
          else cout << " -- is a mirrored palindrome.";

          cout << endl << endl;
     }

     return 0;
}
