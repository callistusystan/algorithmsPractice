#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

int solve() {
  int N, P;
  cin >> N >> P;

  vector<ll> R(N);
  vector<vector<vector<ll>>> Q(N, vector<vector<ll>>(P, vector<ll>(2)));

  for (int i=0;i<N;i++) cin >> R[i];
  for (int i=0;i<N;i++)
    for (int j=0;j<P;j++){
      ll num;
      cin >> num; num*=10;

      ll lower, upper;
      lower = (num+11*R[i]-1)/(11*R[i]); upper = num/(9*R[i]);
      Q[i][j][0] = lower; Q[i][j][1] = upper;
    }

  for (int i=0;i<N;i++)
    sort(Q[i].begin(), Q[i].end());

  vi pointers(N,0);
  int ans = 0, curSize=1;
  // keep looping unless a pointer is out of range
  while (*max_element(pointers.begin(), pointers.end()) < P) {
    // see if all firsts can make serving of curSize
    bool canDo = true;
    for (int i=0;i<N;i++) {
      // since we only care about curSize, ignore anything that is lower than this
      // we pop until we reach something that covers this range
      while (Q[i][pointers[i]][1] < curSize) {
        pointers[i]++;
        if (pointers[i] >= P) return ans;
      }
      // check if curSize fits
      if (!(Q[i][pointers[i]][0] <= curSize && curSize <= Q[i][pointers[i]][1])) canDo = false;
    }

    // if canDo, we increment ans and all pointers
    // else we increment size
    if (canDo) {
      for (int i=0;i<N;i++) pointers[i]++;
      ans++;
    } else
      curSize++;
  }

  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
