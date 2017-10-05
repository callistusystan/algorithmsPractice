#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define EPS

void solve(vector<double> A) {
  sort(A.begin(), A.end());
  double L, H, T;
  L = A[2], H = A[1], T = A[0];

  // check for letter
  if (125 <= L && L <= 290 && 90 <= H && H <= 155 && 0.25 <= T && T <= 7) {
    cout << "letter";
  } else if ((125 <= L && 90 <= H && 0.25 <= T) && (L > 290 || H > 155 || T > 7) && (L <= 380 && H <= 300 && T <= 50)) {
    cout << "packet";
  } else if ((125 <= L && 90 <= H && 0.25 <= T) && (L > 380 || H > 300 || T > 50) && (L + 2*(H+T) <= 2100)) {
    cout << "parcel";
  } else {
    cout << "not mailable";
  }
  cout << endl;
}

int main() {
  vector<double> A(3);
  while (cin >> A[0] >> A[1] >> A[2], A[0] || A[1] || A[2]) {
    solve(A);
  }
  return 0;
}
