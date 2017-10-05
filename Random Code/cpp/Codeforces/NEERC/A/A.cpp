#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi leftmost(105,-1), rightmost(105,-1), visited(105,0);
vi L(105,0),R(105,0);
int compId = 1;

void dfs(int u) {
  visited[u] = compId;
  if (L[u] == 0) leftmost[compId] = u;
  if (R[u] == 0) rightmost[compId] = u;
  if (L[u] != 0 && !visited[L[u]])
    dfs(L[u]);
  if (R[u] != 0 && !visited[R[u]])
    dfs(R[u]);
}

int main() {
  int N; cin >> N;

  for (int i=1;i<=N;i++) {
    cin >> L[i] >> R[i];
  }

  for (int i=1;i<=N;i++) {
    if (!visited[i]) {
      dfs(i);
      compId++;
    }
  }

  for (int i=2;i<compId;i++) {
    R[rightmost[i-1]] = leftmost[i];
    L[leftmost[i]] = rightmost[i-1];
  }

  for (int i=1;i<=N;i++) {
    cout << L[i] << " " << R[i] << endl;
  }

  return 0;
}
