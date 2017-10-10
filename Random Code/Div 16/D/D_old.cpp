#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N,H,V,W;

int getY(int y, int t) {
  return (y + t * V)%H;
}

vector<ii> getDangerRange(int y, int t1, int t2) {
  vector<ii> ans;
  int h1,h2;
  h1 = getY(y, t1);
  h2 = getY(y, t2);
  int tToReachBottom = t1 + (H-h1 +V-1)/V;

  if (t1 <= tToReachBottom && tToReachBottom <= t2) {
    ans.push_back({h1,H});
    int newTToReachBottom = tToReachBottom + (H-getY(y, tToReachBottom) +V-1)/V;
    if (t1 <= newTToReachBottom && newTToReachBottom <= t2)
      ans.push_back({ 0, H });
    else {
      ans.push_back({ 0, h2 });
    }

    return ans;
  } else {
    ans.push_back({h1,h2});
    return ans;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> H >> V >> W;

  vector<ii> dangerRanges;

  for (int i=0;i<N;i++) {
    int x,y; cin >> x >> y;
    vector<ii> ranges = getDangerRange(y, x, x + W);
    for (ii r : ranges) {
      dangerRanges.push_back(r);
    }
  }

  sort(dangerRanges.begin(), dangerRanges.end());
  vector<ii> mergedRanges;
  mergedRanges.push_back(dangerRanges[0]);
  for (int i=1;i<(int)dangerRanges.size();i++) {
    ii cur = dangerRanges[i];
    if (cur.first > mergedRanges.back().second)
      mergedRanges.push_back(cur);
    else
      mergedRanges.back().second = max(mergedRanges.back().second, cur.second);
  }

  if (mergedRanges[0].first > 0 || mergedRanges.back().second < H) {
    cout << "VICTORY" << endl;
    return 0;
  }

  bool canWin = false;
  for (int i=1;i<(int)mergedRanges.size();i++) {
    if (mergedRanges[i].first != mergedRanges[i-1].second+1) {
      canWin = true;
      break;
    }
  }

  if (canWin) {
    cout << "VICTORY" << '\n';
  } else {
    cout << "GAME OVER" << '\n';
  }
  return 0;
}
