#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

long long compute(int n, vi &coefficients) {
  // start with a_n = 0, term = 1
  // at iteration=0, a_n += coefficients[0]*1
  // after each iteration, multiply term by n
  long long a_n = 0, term = 1;

  for (int coeff : coefficients) {
    a_n += coeff*term;
    term *= n;
  }
  return a_n;
}

void solve() {
  int highestPower;
  cin >> highestPower;
  // read input
  string line;
  getline(cin, line);

  istringstream istream(line);
  vi coefficients;
  int coeff, D, K;
  while (istream >> coeff) {
    coefficients.push_back(coeff);
  }

  cin >> D >> K;
  // start with n=1, b_m_length = 0
  // for each n, find a_n using coefficients
  // add n*d to b_m_length
  // if k <= b_m_length, a_n is the answer

  int n = 1, b_m_length = 0;
  while (true) {
    b_m_length += n*D;
    if (K <= b_m_length) {
      long long a_n = compute(n, coefficients);
      cout << a_n << endl;
      return;
    }
    n++;
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin.ignore();
    solve();
  }
  return 0;
}

// 2
