#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int N; cin >> N;
  int cheapest; cin >> cheapest;
  cout << cheapest++;

  for (int i=1;i<N;i++) {
    int cur; cin >> cur;
    if (cur < cheapest) cheapest = cur;
    cout << " " << cheapest++;
  }
  cout << endl;
  return 0;
}
