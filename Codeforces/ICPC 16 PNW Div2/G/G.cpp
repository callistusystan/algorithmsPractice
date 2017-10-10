#include <bits/stdc++.h>

using namespace std;

char a[55][55];

int main() {
    int n, m;  cin >> n >> m;
    char ans[55][55];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') ans[i][j] = '#';
            else ans[i][j] = '.';
        }
    }

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '#') {
                int k = 0;
                while (k < sum) {
                    ans[i-k-1][j] = 'o';
                    k += 1;
                }
                sum = 0;
            }
            else if (a[i][j] == 'o') sum += 1;
        }
        // cout << sum << " " << j << " TEST"  << endl;
        // for (int e = 0; e < n; e ++) {
        //     for (int f = 0; f < m; f ++)
        //         cout << ans[e][f];
        //     cout << endl;
        // }
        if (sum > 0) {
            for (int k = 0; k < sum; k++) {
                ans[n-k-1][j] = 'o';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
