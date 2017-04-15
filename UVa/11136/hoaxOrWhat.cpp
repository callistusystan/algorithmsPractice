#include <bits/stdc++.h>

using namespace std;

int N;

long long solve() {
  long long ans = 0;
  multiset<int> bills;
  for (int i=0;i<N;i++) {
    int K;
    cin >> K;
    while (K--) {
      int num;
      cin >> num;
      bills.insert(num);
    }

    ans += *(--bills.end()) - *(bills.begin());
    multiset<int>::iterator it = bills.begin();
    bills.erase(it);
    it = bills.end();
    it--;
    bills.erase(it);
  }
  return ans;
}

int main() {
  while (cin >> N, N) {
    cout << solve() << endl;
  }
  return 0;
}
