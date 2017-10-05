#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct Eulerian {
  struct edge { int u, v; bool used ; int opp (int x) { return x == u ? v : u; } };
  int n, m; vector <edge > edges ; vvi adj; vi cnt , tour ;
  void dfs ( int u) {
    while ( cnt [u] < ( int )adj [u]. size ()) {
      auto & e = edges [ adj [u][ cnt [u ]++]];
      if (!e. used ) e. used = 1, dfs (e. opp (u)), tour . push_back (u);
    }
    if ( tour . empty ()) tour . push_back (u);
  }
  Eulerian ( int n) : n(n), m (0) , adj (n) { }
  void add_edge ( int u, int v, bool dir) { // dir = true if the edge is directed
    edges . push_back ({u,v ,0}) ; // or false if the edge is undirected
    adj [u]. push_back (m ++) ;
    if (! dir ) adj [v]. push_back (m -1);
    }
  vi find ( int start =0) {
    tour . clear (); cnt . assign (n, 0); for ( auto & e : edges ) e. used = 0;
    dfs ( start ), reverse ( tour . begin () , tour . end ());
    return tour ;
  }
};

string order = "ROYGBV";
map<char, string> conflict;

void solve() {
  int N;
  cin >> N;

  vi count(6);
  for (int i=0;i<6;i++) {
    cin >> count[i];
  }

  Eulerian graph(N);

  vi degree(N,0);

  for (int i=0;i<6;i++) {
    for (int j=i+1;j<6;j++) {
      string invalid = conflict[order[i]];
      if (invalid.find(order[j]) == string::npos) {
        cout << i << " " << j << endl;
        degree[i] += min(count[i],count[j]);
        degree[j] +=min(count[i],count[j]);
        for (int k=0;k<min(count[i],count[j]);k++) {
          graph.add_edge(i,j, false);
        }
      }
    }
  }

  int nOdd = 0, iOdd;
  for (int i=0;i<6;i++) {
    if (degree[i]%2==1) {
      nOdd++;
      iOdd = i;
    }
  }

  if (nOdd > 1) {
    cout << "IMPOSSIBLE";
    return;
  }

  vi tour;
  if (nOdd == 1) {
    tour = graph.find(iOdd);
  } else {
    tour = graph.find(0);
  }

  for (int i: tour) {
    cout << order[i];
  }
}

int main() {
  conflict['R'] = "VRO";
  conflict['O'] = "ROY";
  conflict['Y'] = "OYG";
  conflict['G'] = "YGB";
  conflict['B'] = "GBV";
  conflict['V'] = "BVR";

  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    printf("Case #%d: ", t);
    solve();
    cout << endl;
  }
  return 0;
}
