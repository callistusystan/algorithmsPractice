#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// Maximum unweighted bipartite matching using the Hopcroft - Karp algorithm .
// Returns the number of matches and a vector of each left node ’s match ,
// or -1 if the node had no match . Complexity : O( Sqrt (V) E)
struct bipartite_matching {
  int L, R, p; vi m, used , d; vvi adj ; queue <int > q;
  bool bfs () {
    for (int v =0; v<R; v++) if (! used [v]) d[v] = p, q. push (v);
    while (!q. empty ()) {
      int v = q. front (); q. pop ();
      if (d[v] != d[R]) for ( int u : adj [v]) if (d[m[u]] < p)
      d[m[u]] = d[v] + 1, q. push (m[u]);
    }
    return d[R] >= p;
  }
  int dfs ( int v) {
    if (v == R) return 1;
    for (int u : adj [v]) if (d[m[u]] == d[v] + 1 && dfs (m[u])) return m[u] = v, 1;
      d[v] = d[R]; return 0;
  }

  bipartite_matching ( int l, int r) : L(l), R(r), d(r +1) , adj (r) { }
  void add_edge ( int u, int v) { adj [v]. push_back (u); }
  pair <int , vi > match () {
    int res = 0; m. assign (L, R), used . assign (R+1, 0);
    for (p =0; bfs (); p = d[R ]+1) for (int v =0; v<R; v++)
      if (! used [v] && dfs (v)) used [v] = 1, res ++;
    replace (m. begin () , m.end () , R, -1); return {res , m};
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  vector<bool> rowsUsed(N, false), colsUsed(N, false), posDiagUsed(2*N-1, false), negDiagUsed(2*N-1, false);
  vector<vector<char>> stage(N,vector<char>(N, '.'));

  for (int m=0;m<M;m++) {
    char c;
    int row, col;
    cin >> c >> row >> col;
    row--; col--;
    stage[row][col] = c;

    // disable rows/cols/diags that were used
    if (c == '+' || c == 'o') {
      int posDiag, negDiag; // posDiag = /
      posDiag = row+col; negDiag = row-col;
      negDiag+=N-1;
      posDiagUsed[posDiag] = true;
      negDiagUsed[negDiag] = true;
    }
    if (c == 'x' || c == 'o') {
      rowsUsed[row] = true;
      colsUsed[col] = true;
    }
  }

  // set up graph
  bipartite_matching rooks(N, N), bishops(2*N-1,2*N-1);

  // add edges for rooks
  for (int i=0;i<N;i++)
    if (!rowsUsed[i])
      for (int j=0;j<N;j++)
        if (!colsUsed[j])
          rooks.add_edge(i,j);

  // add edges for bishops
  for (int i=0;i<N;i++)
    for (int j=0;j<N;j++) {
      int posDiag, negDiag; // posDiag = /
      posDiag = i+j; negDiag = i-j;
      negDiag += N-1;
      if (!posDiagUsed[posDiag] && !negDiagUsed[negDiag])
        bishops.add_edge(posDiag,negDiag);
    }

  // perform matching
  pair<int, vi> resultRooks = rooks.match(), resultBishops = bishops.match();

  // update stage and note changes
  vector<pair<int, int>> changes;
  int points = 0;
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      int posDiag, negDiag; // posDiag = /
      posDiag = i+j; negDiag = i-j;
      negDiag += N-1;

      char orig = stage[i][j];
      if (orig == 'o') {
        points+=2;
      } else {
        bool isRook = false, isBishop = false;
        if (orig == 'x' || resultRooks.second[i] == j) isRook = true;
        if (orig == '+' || resultBishops.second[posDiag] == negDiag) isBishop = true;

        if (isRook && isBishop) {
          stage[i][j] = 'o';
          points += 2;
        } else if (isRook) {
          stage[i][j] = 'x';
          points++;
        } else if (isBishop) {
          stage[i][j] = '+';
          points++;
        }

        if (stage[i][j] != orig) changes.push_back(make_pair(i,j));
      }
    }
  }

  cout << points << " " << changes.size() << endl;
  for (pair<int, int> p : changes) {
    cout << stage[p.first][p.second] << " " << p.first+1 << " " << p.second+1 << endl;
  }
}

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
