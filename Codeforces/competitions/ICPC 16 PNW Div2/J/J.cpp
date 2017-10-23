#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N, K;

ll calcT(vector<ii> &pos) {
  sort(pos.begin(), pos.end());
  ll t = 0;

  int i = (int)pos.size()-1;
  while (i >= 0) {
    ll trips = (pos[i].Y + K-1)/K;

    t += (ll)2*trips*pos[i].X;
    ll remaining = trips*K - pos[i].Y;
    i--;
    while (i >= 0 && remaining > 0) {
      if (pos[i].Y > remaining) {
        pos[i].Y -= remaining;
        remaining = 0;
      } else if (pos[i].Y == remaining) {
        remaining = 0;
        i--;
      } else if (pos[i].Y < remaining) {
        remaining -= pos[i].Y;
        i--;
      }
    }
  }
  return t;
}

int main() {
  cin >> N >> K;

  vector<ii> pos1, pos2;
  for (int i=0;i<N;i++) {
    int xi, mi; cin >> xi >> mi;
    if (xi > 0) pos1.push_back({ xi, mi });
    else if (xi < 0) pos2.push_back({ abs(xi), mi });
  }

  cout << calcT(pos1) + calcT(pos2) << endl;

  return 0;
}
