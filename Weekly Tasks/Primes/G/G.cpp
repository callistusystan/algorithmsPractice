#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int N; cin >> N;
  vector<string> S(N);
  vi count(10,0);
  for (int i=0;i<N;i++) {
    cin >> S[i];
    for (int j=0;j<7;j++)
      if (S[i][j] == '1') count[j]++;
  }

  cout << *max_element(count.begin(), count.end()) << endl;

  return 0;
}
