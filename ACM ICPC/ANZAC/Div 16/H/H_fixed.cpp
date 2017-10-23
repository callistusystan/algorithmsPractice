#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

double EPS = 1e-9;

double memo[85][85][100];

double accept_ans(int l, int r, int p) {
    return (r-p+1)/1.0/(r-l+1);
}

double reject_ans(int l, int r, int p) {
    return (p-l)/1.0/(r-l+1);
}

/*
DP[L][R][S] = max from L <= P <= R
    ((R-p+1)/(R-L+1) * max(P, DP[P][R][S-2])
      + (P-L)/(R-L+1)*DP[L][P-1][S-1])
*/

double dp(int l, int r, int s) {
    if (s <= 0) return memo[l][r][s] = 0;
    else if (memo[l][r][s] != -1) return memo[l][r][s];
    double ans = 0;
    for (int p = l; p <= r; p++) {
        double valFromThis = 0, bigger;
        if (p > dp(p,r,s-2) + EPS) bigger = p;
        else bigger = dp(p,r,s-2);

        valFromThis = accept_ans(l, r, p) * bigger + reject_ans(l, r, p) * dp(l, p-1, s-1);
        if (valFromThis > ans + EPS) ans = valFromThis;
    }
    return memo[l][r][s] = ans;
}

int main() {
    int L, R, T;  cin >> L >> R >> T;
    T /= 100;
    for (int i=0;i<85;i++)
      for (int j=0;j<85;j++)
        for (int k=0;k<100;k++)
          memo[i][j][k] = -1;
    cout << fixed << setprecision(10) << dp(L, R, T) << endl;
    return 0;
}
