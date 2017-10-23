#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    long long ans = 0;
    string word;
    cin >> word;
    int N = word.size();

    if (N == 1) {
      ans = 1;
    }
    else {
      ans = 1;
      if (word[0] != word[1])
        ans *= 2;
      if (word[N-1] != word[N-2])
        ans *= 2;
      for (int i=1;i<word.length()-1;i++) {
        int st = i-1;
        set<char> k(word.begin() + st, word.begin() + st+3);
        ans *= k.size();
        ans %= 1000000007;
      }
    }
    ans %= 1000000007;
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
