#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  string line;

  int nEdges = 0;
  bitset<26> hasEdge;
  while (cin >> line, line[0] != '*') {
    hasEdge.set(line[1]-'A');
    hasEdge.set(line[3]-'A');
    nEdges++;
  }
  cin >> line;
  int nVertices = 0;
  for (char c:line) {
    if (c == ',') continue;
    nVertices++;
  }

  int nVerticesInTrees = hasEdge.count();
  int nAcorns = nVertices - nVerticesInTrees;

  int nTrees = 0;
  // if 1 tree, V-1 edges
  // if 2 trees, A-1 + B-1 edges, where A+B = V, thus V-2 edges
  // if n trees, V-n edges
  while (nVerticesInTrees != nEdges) {
    nVerticesInTrees--;
    nTrees++;
  }

  printf("There are %d tree(s) and %d acorn(s).\n", nTrees, nAcorns);
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
