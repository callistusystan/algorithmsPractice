#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// Union - Find with union -by -rank , path compression , component size and count
// number of connected components . Complexity : O( log *(N)) amortized per query .
struct UnionFind {
  int n; vi A, s, rank ;
  UnionFind ( int n) : n(n), A(n), s(n, 1) , rank (n) { iota (A. begin () , A.end () , 0); }
  int find ( int x) { return A[x]==x ? x : A[x]= find (A[x]); }
  bool merge ( int x, int y) { // Connect x and y. Returns false if x and y were
    x = find (x); y = find (y); // already connected , true otherwise
    if (x == y) return false ;
    if ( rank [x] < rank [y]) swap (x, y);
    A[y] = x; s[x] += s[y]; n --;
    if ( rank [x] == rank [y]) rank [x ]++;
    return true ;
  }
  bool connected ( int x, int y) { return ( find (x) == find (y)); }
  int size ( int x) { return s[ find (x)]; } // Returns the size of the set representing x
  int num_sets () { return n; } // Returns the number of connected components
};

void solve() {
  int N;
  cin >> N;
  cin.ignore();
  UnionFind mySet(N);

  string line;
  int correct = 0, incorrect = 0;
  while (getline(cin, line), line != "") {
    istringstream istream(line);
    char c;
    int a, b;
    istream >> c >> a >> b;
    a--;b--;
    if (c == 'c') {
      mySet.merge(a,b);
    } else {
      if (mySet.connected(a,b)) correct++;
      else incorrect++;
    }
  }
  printf("%d,%d\n", correct, incorrect);
}

int main() {
  int T;
  cin >> T;
  cin.ignore();
  while (T--) {
    solve();
    if (T) cout << endl;
  }
  return 0;
}
