#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

double EPS = 1e-9;
double memo[85][85][10005];

double accept_ans(int l, int r, int p) {
    return (r-p+1)/1.0/(r-l+1);
}

double reject_ans(int l, int r, int p) {
    return (p-l)/1.0/(r-l+1);
}

double dp(int l, int r, int s) {
    if (s == 0) return memo[l][r][s] = 0;
    if (memo[l][r][s] != -1) return memo[l][r][s];

    double ans = 0;
    for (int p = l; p <= r; p++) {
      if (s < 100) continue;
        double apt = accept_ans(l, r, p), rjt;
        if (p > dp(p, r, s-200) + EPS) apt *=  p;
        else apt *= dp(p, r, s-200);

        rjt = reject_ans(l, r, p) * dp(l, p-1, s-100);

        if (ans + EPS < apt + rjt) ans = apt + rjt;
    }
    cout << "memo[" << l << "][" << r << "][" << s << "] = " << ans << endl;
    return memo[l][r][s] = ans;
}

int main() {
    int L, R, T;  cin >> L >> R >> T;

    for (int i = 0; i < 85; i++) {
        for (int j = 0; j < 85; j++) {
            for (int k = 0; k < 10005; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    cout << fixed << setprecision(10) << dp(L, R, T) << endl;
    return 0;
}
