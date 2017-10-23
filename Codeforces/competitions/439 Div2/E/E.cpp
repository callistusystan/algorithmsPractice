#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vi freq(26,0);
    for (int i=0;i<N;i++) {
      string s; cin >> s;
      freq[tolower(s[0]) - 'a']++;
    }
    freq['b'-'a']/=2;
    vi ans({freq['k'-'a'],freq['l'-'a'], freq['b'-'a']});
    cout << *min_element(ans.begin(), ans.end()) << endl;
  }
  return 0;
}
