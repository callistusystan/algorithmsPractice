#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ll INF = numeric_limits <ll>:: max ()/2;

// Dinic ’s algorithm for maximum flow . add_edge returns the id of an edge which can be
// used to inspect the final flow value using get_edge (i). flow . Complexity : O(V^2 E)
template < typename T> struct Dinics {
  struct edge { int to; T flow , cap ; }; T INF = numeric_limits <T >:: max ();
  int n, m; vi dist , work ; queue <int > q; vector <edge > edges ; vvi adj ;
  vi from;
  bool bfs ( int s, int t) {
    dist . assign (n, -1); dist [s] = 0; q. push (s);
    while (!q. empty ()) {
      int u = q. front (); q. pop ();
      for ( auto & i : adj[u]) {
      edge & e = edges [i]; int v = e.to;
      if ( dist [v] < 0 && e. flow < e.cap) dist [v] = dist [u] + 1, q. push (v);
      }
    }
    return dist [t] >= 0;
  }
  T dfs( int u, int t, T f) {
    if (u == t) return f;
    for (int& i = work [u]; i < ( int ) adj [u]. size (); i ++) {
      auto & e = edges [ adj [u][i]], & rev = edges [ adj [u][i ]^1];
      if (e. flow < e. cap && dist [e.to] == dist [u] + 1) {
        T df = dfs (e.to , t, min(f, e.cap - e. flow ));
        if (df > 0) {
          from[e.to] = u; e. flow += df; rev . flow -= df; return df; }
      }
    }
    return 0;
  }
  // Create a flow network with n nodes -- add edges with add_edge (u,v, cap )
  Dinics ( int n) : n(n), m (0) , adj (n), from(n,-1) { }
  int add_edge ( int from , int to , T cap ) { // add an edge ( from -> to) with
    adj [ from ]. push_back (m++) , adj [to ]. push_back (m ++) ; // capacity of cap units .
    edges . push_back ({to , 0, cap }) , edges . push_back ({ from , 0, 0}) ;
    return m - 2; // Change {from ,0 ,0} to {from ,0, cap } for bidirectional edges
  }
  edge & get_edge ( int i) { return edges [i]; } // get a reference to the i’th edge
  int getFrom (int i) { return from[i]; }
  T max_flow ( int s, int t) { // find the maximum flow from s to t
    T res = 0; for ( auto & e : edges ) e. flow = 0;
    while ( work . assign (n, 0) , bfs (s, t))
    while (T delta = dfs (s, t, INF )) res += delta ;
    return res;
  }
};

void solve(string line) {
  Dinics<ll> graph = Dinics<ll>(38);
  // 2 for s and t 0 = s, 1 = t
  // 26 for alphabets 2..27 = alphabets
  // 10 for computers 28..37 = computers
  for (int i=0;i<10;i++) {
    graph.add_edge(i+28,1,1);
  }
  ll expMaxFlow = 0;

  do {
    int U = line[0] - 'A';
    int C = line[1] - '0';
    expMaxFlow += C;
    graph.add_edge(0,U+2,C);

    int i = 3;
    while (line[i] != ';') {
      graph.add_edge(U+2, line[i]-'0'+28, LLONG_MAX/2);
      i++;
    }
  } while (getline(cin, line), line.size() > 1);

  ll maxFlow = graph.max_flow(0,1);

  if (maxFlow == expMaxFlow){
    for (int i=0;i<10;i++) {
      if (graph.getFrom(i+28) != -1)
        cout << (char)(graph.getFrom(i+28)-2+'A');
      else
        cout << "_";
    }
  } else {
    cout << "!";
  }
  cout << endl;
}

int main() {
  vector<string> lines;
  string line;
  while (getline(cin, line)) {
    solve(line);
  }
  return 0;
}
