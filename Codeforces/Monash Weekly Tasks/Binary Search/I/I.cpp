#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N;
vector<pii> dishes;

bool f(int minutes) {
  vi used(10005, false);
  for (pii dish: dishes) {
    int t = 0;
    if (dish.Y - dish.X < minutes) return false;
    for (int i=dish.X;i<dish.Y;i++) {
      if (!used[i]) {
        used[i] = true;
        t++;
      }
      if (t == minutes) break;
    }
    if (t < minutes) return false;
  }
  return true;
}

bool cmp(pii a, pii b) {
  if (a.Y-a.X != b.Y-b.X) return a.Y-a.X < b.Y-b.X;
  return a.X < b.X;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> N;
  dishes.resize(N);
  for (int i=0;i<N;i++) {
    int ai,bi; cin >> ai >> bi;
    dishes[i] = {ai,bi};
  }

  sort(dishes.begin(), dishes.end(), cmp);

  int lo = 0, hi = 10005, i = 0;
  while (lo != hi-1 && i++ < 30) {
    int mid = lo + (hi-lo)/2;
    if (f(mid)) lo = mid;
    else hi = mid;
  }

  cout << lo*N << endl;
  return 0;
}
