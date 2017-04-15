#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int R,C,nBlank;
vector<string> cake;

void expand(int i, int j) {
  char c = cake[i][j];
  int k = j-1;
  while (k >= 0 && cake[i][k] == '?') {
    cake[i][k] = c;
    k--;
    nBlank--;
  }
  k = j+1;
  while (k < C && cake[i][k] == '?') {
    cake[i][k] = c;
    k++;
    nBlank--;
  }
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    cin >> R>> C;

    cake = vector<string>(R);
    for (int i=0;i<R;i++) {
      cin >> cake[i];
    }

    vector<bool> hasComp(R,false);

    nBlank = 0;

    for (int i=0;i<R;i++) {
      for (int j=0;j<C;j++) {
        if (cake[i][j] == '?') nBlank++;
        else {
          hasComp[i] = true;
        }
      }
    }

    vector<bool> hasExpanded(R,false);

    while (nBlank>0) {
      for (int i=0;i<R;i++) {
        if (hasComp[i] && !hasExpanded[i]) {
          for (int j=0;j<C;j++) {
            if (cake[i][j] != '?') {
              expand(i,j);
              hasExpanded[i] = true;
            }
          }
        } else if (!hasExpanded[i]) {
          if (i != R-1 && hasExpanded[i+1]) {
            for (int j=0;j<C;j++) {
              cake[i][j] = cake[i+1][j];
              nBlank--;
            }
            hasExpanded[i] = true;
          } else if (i >= 1 && hasExpanded[i-1]) {
            for (int j=0;j<C;j++) {
              cake[i][j] = cake[i-1][j];
              nBlank--;
            }
            hasExpanded[i] = true;
          }
        }
      }
    }

    cout << "Case #" << t << ": " << endl;
    for (string s : cake) cout << s << endl;
  }
  return 0;
}
