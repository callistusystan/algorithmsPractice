#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N, int M) {
  vvi indices1(N+5), indices2(M+5), values(M+5);
  for (int n=1;n<=N;n++) {
    int R, v;
    cin >> R;
    for (int j=0;j<R;j++) {
      cin >> v;
      indices1[n].push_back(v);
      indices2[v].push_back(n);
    }
    for (int j=0;j<R;j++) {
      cin >> v;
      values[indices1[n][j]].push_back(v);
    }
  }

  printf("%d %d\n", M, N);
  for (int m=1;m<=M;m++) {
    cout << indices2[m].size();
    for (int i=0;i<(int)indices2[m].size();i++)
      cout << " " << indices2[m][i];
    cout << endl;
    for (int i=0;i<(int)indices2[m].size();i++) {
      if (i) cout << " ";
      cout << values[m][i];
    }
    cout << endl;
  }
}

int main() {
  int N, M;
  while (cin >> N >> M) {
    solve(N, M);
  }
  return 0;
}
