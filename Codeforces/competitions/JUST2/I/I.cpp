#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int N; cin >> N;
  vector<vi> t(N,vi(N));
  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++)
      cin >> t[i][j];

  for (int i=0;i<N;i++) {
    cout << (int)sqrt(t[i][i]) << " \n"[i==N-1];
  }

  return 0;
}
