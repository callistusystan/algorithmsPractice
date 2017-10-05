#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N,H,V,W;
vector<ii> drops;

bool covered() {
  vi badYs;
  for (ii d : drops) {
    badYs.push_back((d.Y + d.X*V)%H);
  }
  int interval = V*W + 1;
  sort(badYs.begin(), badYs.end());

  for (int i=0;i<N-1;i++) {
    if (badYs[i] + interval < badYs[i+1])
      return false;
  }

  if (badYs.back() + interval < badYs[0] + H)
    return false;
    
  return true;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> H >> V >> W;

  for (int i=0;i<N;i++) {
    int x,y; cin >> x >> y;
    drops.push_back({x,y});
  }

  if (covered()) {
    cout << "GAME OVER" << '\n';
  } else {
    cout << "VICTORY" << '\n';
  }
  return 0;
}
