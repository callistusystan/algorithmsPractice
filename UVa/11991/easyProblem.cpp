#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N, int M) {
  vvi valueIndices(1000005);
  for (int i=1;i<=N;i++) {
    int v;
    cin >> v;
    valueIndices[v].push_back(i);
  }

  for (int i=0;i<M;i++) {
    int k,v;
    cin >> k >> v;
    k--;
    if (k < (int)valueIndices[v].size())
      cout << valueIndices[v][k];
    else
      cout << 0;
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
