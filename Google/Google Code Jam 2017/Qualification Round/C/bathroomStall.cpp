#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll done,y,z;

void getAns(ll N, ll K, map<ll, ll> &myMap) {
  // calculate y and z for this node
  ll L = 0, R = N-1;
  ll mid = (L+R)/2;

  ll Ls, Rs;
  Ls = mid-L; Rs = R-mid;
  y = max(Ls, Rs);
  z = min(Ls, Rs);

  // count how many times this node is done
  ll nThisNodeDone = myMap[N];
  done += nThisNodeDone;

  myMap.erase(N);
  if (done >= K) return;

  myMap[y] += nThisNodeDone;
  myMap[z] += nThisNodeDone;
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    ll N, K;
    cin >> N >> K;
    // cerr << N << " " << K << endl;

    done = 0;

    map<ll, ll> myMap;

    myMap[N] = 1;
    // ll done = 0;
    while (!myMap.empty() && done < K) {
      // get sequence with biggest size
      map<ll, ll>::iterator it = myMap.end();
      it--;
      pair<ll, ll> biggestPair = *it;

      ll biggestN = biggestPair.first;
      getAns(biggestN, K, myMap);
      myMap.erase(N);
    }

    cout << "Case #" << t << ": " << y << " " << z << endl;
  }
  return 0;
}
