#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

double EPS = 1e-9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  int T; cin >> T;
  while (T--) {
    double a,b,c,d;
    cin >> a >> b >> c >> d;

    double LHS,RHS;
    LHS = b*log(a);
    RHS = d*log(c);
    if (LHS < RHS - EPS) cout << "<";
    else cout << ">";
    cout << endl;
  }
  return 0;
}
