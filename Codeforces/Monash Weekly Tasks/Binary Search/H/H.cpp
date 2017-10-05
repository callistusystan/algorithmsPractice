#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

double EPS = 1e-6;
int N, M, X;
vector<tuple<int,int,double>> edges;

template < typename T> struct Dinics {
struct edge { int to; T flow , cap ; }; T INF = numeric_limits <T >:: max ();
int n, m; vi dist , work ; queue <int > q; vector <edge > edges ; vvi adj ;
bool bfs ( int s, int t) {
dist . assign (n, -1); dist [s] = 0; q. push (s);
while (!q. empty ()) {
int u = q. front (); q. pop ();
for ( auto & i : adj[u]) {
edge & e = edges [i]; int v = e.to;
if ( dist [v] < 0 && e. flow < e. cap) dist [v] = dist [u] + 1, q. push (v);
}
}
return dist [t] >= 0;
}T
dfs( int u, int t, T f) {
if (u == t) return f;
for (int& i = work [u]; i < ( int ) adj [u]. size (); i ++) {
auto & e = edges [ adj [u][i]], & rev = edges [ adj [u][i ]^1];
if (e. flow < e. cap && dist [e.to] == dist [u] + 1) {
T df = dfs (e.to , t, min(f, e.cap - e. flow ));
if (df > 0) { e. flow += df; rev . flow -= df; return df; }
}
}
return 0;
}
// Create a flow network with n nodes -- add edges with add_edge (u,v, cap )
Dinics ( int n) : n(n), m (0) , adj (n) { }
int add_edge ( int from , int to , T cap ) { // add an edge ( from -> to) with
adj [ from ]. push_back (m++) , adj [to ]. push_back (m ++) ; // capacity of cap units .
edges . push_back ({to , 0, cap }) , edges . push_back ({ from , 0, 0}) ;
return m - 2; // Change {from ,0 ,0} to {from ,0, cap } for bidirectional edges
}
edge & get_edge ( int i) { return edges [i]; } // get a reference to the i’th edge
T max_flow ( int s, int t) { // find the maximum flow from s to t
T res = 0; for ( auto & e : edges ) e. flow = 0;
while ( work . assign (n, 0) , bfs (s, t))
while (T delta = dfs (s, t, INF )) res += delta ;
return res;
}
};

bool f(double w) {
  Dinics<long long> d(N);
  for (auto e : edges) {
    int a,b; double c;
    a = get<0>(e); b = get<1>(e); c = get<2>(e);
    d.add_edge(a,b,min((ll)X, (ll)(c/w)));
  }

  return d.max_flow(0,N-1) >= X;
}

int main() {
  cin >> N >> M >> X;

  edges.resize(M);
  for (int i=0;i<M;i++) {
    int ai,bi; double ci; cin >> ai >> bi >> ci;
    ai--;bi--;
    edges[i] = make_tuple(ai,bi,ci);
  }

  double lo,hi;
  lo = 0; hi = 1e6 + EPS;
  while (X*hi - X*lo > EPS) {
    double mid = (lo+hi)/2;
    if (f(mid)) {
      lo = mid;
    }
    else hi = mid;
  }

  cout << fixed << setprecision(10) << lo * X << endl;
  return 0;
}
