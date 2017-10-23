#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

string S;
int N;

void solve() {
  cin >> S; N = S.length();
  if (N < 6) cout << N << endl;
  else {
    if ((S[0] == S[2] && S[0] == S[4] && S[1] == S[3] && S[1] == S[5]) || (S[0] == S[3] && S[1] == S[4] && S[2] == S[5])) {
      cout << 5 << endl;
    } else {
      cout << 6 << endl;
    }
  }
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
