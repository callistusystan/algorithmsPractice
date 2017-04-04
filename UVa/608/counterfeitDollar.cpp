#include <bits/stdc++.h>

using namespace std;

string letters = "ABCDEFGHIJKL";
vector<vector<string>> conditions(3, vector<string>(3));

bool test(char coin, bool isLighter) {
    for (int i=0;i<3;i++) {
        int leftWeight = 0, rightWeight = 0;
        for (char c : conditions[i][0])  {
            if (c == coin) {
                // if lighter, dont add weight
                if (!isLighter) leftWeight += 2;
            } else leftWeight++;
        }

        for (char c : conditions[i][1])  {
            if (c == coin) {
                // if lighter, dont add weight
                if (!isLighter) rightWeight += 2;
            } else rightWeight++;
        }

        if (conditions[i][2] == "even") {
            if (leftWeight != rightWeight) return false;
        } else if (conditions[i][2] == "up") {
            if (leftWeight <= rightWeight) return false;
        } else { // down
            if (leftWeight >= rightWeight) return false;
        }
    }

    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                cin >> conditions[i][j];
        for (int i=0;i<12;i++) {
            // assume lighter
            if (test(letters[i], true)) {
                printf("%c is the counterfeit coin and it is light.\n", letters[i]);
                break;
            }

            // assume heavier
            if (test(letters[i], false)) {
                printf("%c is the counterfeit coin and it is heavy.\n", letters[i]);
                break;
            }
        }
    }
    return 0;
}
