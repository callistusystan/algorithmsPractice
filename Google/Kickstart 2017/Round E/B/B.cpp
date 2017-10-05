#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, actualN;
vi sticks(5005), freq(5005);

bool isValid(vi &cur) {
  for (int i=0;i<4;i++) {
    for (int j=i+1;j<4;j++) {
      if (cur[i] == cur[j]) {
        int k = 0, l = 0;
        while (k == i || k == j) k++;
        while (l == i || l == j || l == k) l++;
        double base = ((double)(max(cur[l],cur[k])-min(cur[l],cur[k])))/2;
        if ((cur[l] != cur[k]) && (base < cur[i])) return true;
      }
    }
  }
  return false;
}

ll rec(int id, vi &cur) {
  if (id == N) {
    if ((int)cur.size() == 4 && isValid(cur)) return 1;
    else return 0;
  }

  ll ans = rec(id +1, cur);

  if (cur.size() < 4) {
    cur.push_back(sticks[id]);
    ans += rec(id +1, cur);
    cur.pop_back();
  }

  return ans;
}

ll recLarge(int id, vi &cur) {
  if (id == N) {
    if ((int)cur.size() == 4 && isValid(cur)) return 1;
    else return 0;
  }

  ll ans = recLarge(id +1, cur);

  if (cur.size() < 4) {
    cur.push_back(sticks[id]);
    ans += recLarge(id +1, cur);
    cur.pop_back();
  }

  return ans;
}

void solve() {
  fill(sticks.begin(), sticks.end(), 0);
  fill(freq.begin(), freq.end(), 0);
  map<int, int> lenToId;
  cin >> N;
  actualN = 0;
  for (int i=0;i<N;i++) {
    int cur; cin >> cur;
    if (!lenToId.count(cur)) {
      sticks[actualN] = cur;
      lenToId[cur] = actualN++;
    }
    freq[lenToId[cur]]++;
  }

  for (int i=0;i<actualN;i++) {
    cout << sticks[i] << " " << freq[i] << endl;
  }

  return;

  vi cur;

  cout << recLarge(0, cur) << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++){
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
