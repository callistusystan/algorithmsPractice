// https://www.hackerrank.com/challenges/taum-and-bday

#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    int B, W;
    long long X, Y, Z;
    cin >> B >> W >> X >> Y >> Z;

    long long total = B*X + W*Y;
    if (X + Z < Y) {
      total = 1LL*B*X + W*(X+Z);
    } else if (Y + Z < X) {
      total = 1LL*B*(Y+Z) + W*Y;
    }

    cout << total << endl;
  }
  return 0;
}
