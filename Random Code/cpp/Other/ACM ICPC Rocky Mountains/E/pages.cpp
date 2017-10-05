#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


void solve(int N) {
  string line; cin >> line;
  istringstream istream(line);
  vector<bool> isPrinted(1005, false);
  bool isFirst = true, readComma = false;
  while (true) {
    int L, R; char c;
    if (readComma && !isFirst) {
      if (!(istream >> c)) {
        break;
      }
    }

    istream >> L >> c;
    readComma = true;

    if (c != '-' && L <= N) {
      isPrinted[L] = true;
      readComma = false;
    } else {
      istream >> R;

      for (int j=L;j<min(N, R)+1;j++) {
        isPrinted[j] = true;
      }
    }
    isFirst = false;
  }

  int ans = 0;
  for (int i=0;i<1000;i++) {
    if (isPrinted[i]) ans++;
  }
  cout << ans << endl;
}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
