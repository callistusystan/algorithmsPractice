#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool hasConflict(int N, int M) {
  bitset<1000005> isUsed;
  bool ans = true;
  while (N--) {
    int a,b;
    cin >> a >> b;
    for (int i=a;i<b;i++) {
      if (isUsed.test(i))
        ans = false;
      isUsed.set(i);
    }
  }

  while (M--) {
    int a,b,c;
    cin >> a >> b >> c;
    while (a < 1000000) {
      for (int i=a;i<b;i++) {
        if (i >= 1000000) break;
        if (isUsed.test(i))
          ans = false;
        isUsed.set(i);
      }
      a += c;
      b = min(b+c, 1000000);
    }
  }

  return ans;
}

int main() {
  int N, M;
  while (cin >> N >> M, N || M) {
    if (hasConflict(N, M))
      cout << "NO CONFLICT";
    else cout << "CONFLICT";
    cout << endl;
  }
  return 0;
}
