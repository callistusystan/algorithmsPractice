#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi A(2005), B(2005);
vi appear(2e6+5);

int main() {
  int N; cin >> N;
  for (int i=0;i<N;i++) {
    cin >> A[i];
    appear[A[i]] = 1;
  }
  for (int i=0;i<N;i++) {
    cin >> B[i];
    appear[B[i]] = 1;
  }

  int cnt = 0;
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      int val = A[i]^B[j];
      if (val < 2e6+5 && appear[val]) {
        cnt++;
      }
    }
  }
  if (cnt%2 == 0) cout << "Karen";
  else cout << "Koyomi";
  cout << endl;
  return 0;
}
