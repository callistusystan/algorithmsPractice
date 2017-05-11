#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N) {
  bool isA = true;
  int a=0,b=0;
  for (int i=0;i<32;i++){
    if (N & (1<<i)) {
      if (isA) a |= (1<<i);
      else b |= (1<<i);
      isA = !isA;
    }
  }
  cout << a << " " << b << endl;
}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
