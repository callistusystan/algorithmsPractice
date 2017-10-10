#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int N, X; cin >> N >> X;
  vi used(105, 0);
  for (int i=0;i<N;i++) {
    int num; cin >> num;
    used[num] = true;
  }

  int ans = 0;
  if (used[X]) ans++;
  for (int i=0;i<X;i++) {
    if (!used[i]) ans++;
  }

  cout << ans << endl;


  return 0;
}
