#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool inRange(double A, double B, double C) {
  return (B <= A && A <= C);
}

void solve(vector<double> A) {
  sort(A.begin(), A.end());
  double L, H, T;
  L = A[2], H = A[1], T = A[0];

  // check for letter
  if (inRange(L, 125, 290) && inRange(H, 90, 155) && inRange(T, 0.25, 7)) {
    cout << "letter";
  } else if (inRange(L, 125, 380) && inRange(H, 90, 300) && inRange(T, 0.25, 50)) {
    cout << "packet";
  } else if (L >= 125 && H >= 90 && T >= 0.25 && 2*H + 2*T <= 2100) {
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
