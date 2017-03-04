#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    int N,K;
    cin >> N >> K;
    vector<int> A(N),B(N),C(N),D(N);
    for(int i=0;i<N;i++)
      cin >> A[i];
    for(int i=0;i<N;i++)
      cin >> B[i];
    for(int i=0;i<N;i++)
      cin >> C[i];
    for(int i=0;i<N;i++)
      cin >> D[i];

    map<int, int> abXor;

    for (int i=0;i<N;i++) {
      for (int j=0;j<N;j++) {
        abXor[A[i]^B[j]]++;
      }
    }

    long long ans = 0;

    for (int i=0;i<N;i++) {
      for (int j=0;j<N;j++) {
        if (abXor.count(C[i]^D[j]^K))
          ans += abXor[C[i]^D[j]^K];
      }
    }
    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
