#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int T = 0;

void solve(int K) {
  if (T++ > 0) cout << endl;
  vi S(K);
  for (int i=0;i<K;i++) cin >> S[i];

  sort(S.begin(), S.end());

  for (int a=0;a<K-5;a++)
    for (int b=a+1;b<K-4;b++)
      for (int c=b+1;c<K-3;c++)
        for (int d=c+1;d<K-2;d++)
          for (int e=d+1;e<K-1;e++)
            for (int f=e+1;f<K;f++)
              printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
}

int main() {
  int K;
  while (cin >> K, K) {
    solve(K);
  }
  return 0;
}
