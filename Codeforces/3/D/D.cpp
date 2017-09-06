#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<ll, int> lli;
typedef vector<lli> vlli;

int SOURCE = 0;
int SINK = 1;

vector <pair<ll, int> > slow_factors (ll n) {
vector <pair<ll,int>> res ;
for (ll i = 2; i*i <= n; ++i) if (n % i == 0) { // change if to while for duplicates
res . push_back ({i,0});
while (n % i == 0) {
  n /= i; // remove while to include duplicates
  res.back().second++;
}
}
if (n > 1) res. push_back ({n,1});
return res;
}

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

void solve() {
  int N, M;
  cin >> N >> M;

  // read A, while computing the prime factors of each A[i]
  vi A(N);
  vector<vector<lli>> pf(N);
  int maxNoOfPF = 0;
  for (int i=0;i<N;i++) {
    cin >> A[i];
    auto A_i_factors = slow_factors(A[i]);
    maxNoOfPF = max(maxNoOfPF, (int) A_i_factors.size());
    for (lli p: A_i_factors) {
      pf[i].push_back(p);
    }
  }

  // read in edges, and sort them
  vii edges(M);
  for (int i=0;i<M;i++) {
    int u,v; cin >> u >> v;
    u--; v--;
    if (u%2 != 0) {
      int tmp = u;
      u = v;
      v = tmp;
    }
    edges[i] = {u,v};
  }
  // make dinics
  Dinics<ll> d(2 + N + N*maxNoOfPF);

  vector<bool> done(N, false);
  // iterate edges and make prime vertices as required
  for (ii e : edges) {
    int u,v; u = e.first, v = e.second;
    // cerr << "PROCESSING " << u << " " << v << endl;
    if (!done[u]) {
      // cerr << "adding edge from source to " << u << endl;
      d.add_edge(SOURCE, 2+u, LLONG_MAX/2);
      for (int i=0;i<(int)pf[u].size();i++) {
        lli curPf = pf[u][i];
        // cerr << " adding edge from " << u << " to PF " << curPf.first << " with cap " << curPf.second << endl;
        d.add_edge(2+u, 2+N+u*maxNoOfPF+i, curPf.second);
      }
      done[u] = true;
    }
    if (!done[v]) {
      // cerr << "adding edge from " << v << " to sink" << endl;
      d.add_edge(2+v, SINK, LLONG_MAX/2);
      for (int i=0;i<(int)pf[v].size();i++) {
        lli curPf = pf[v][i];
        // cerr << " adding edge from PF " << curPf.first << " to " << v <<" with cap " << curPf.second << endl;
        d.add_edge(2+N+v*maxNoOfPF+i, 2+v, curPf.second);
      }
      done[v] = true;
    }

    // add edge between PF of u and v
    // cerr << " ADDING EDGES BETWEEN PRIME FACTORS " << endl;
    int i,j; i = j = 0;
    while (i < (int)pf[u].size() && j < (int)pf[v].size()) {
      if (pf[u][i].first == pf[v][j].first) {
        // cerr << " adding edge from PF " << pf[u][i].first << " to PF " << pf[v][j].first << " with cap " << min(pf[u][i].second, pf[v][j].second) <<endl;
        d.add_edge(2+N+u*maxNoOfPF+i, 2+N+v*maxNoOfPF+j, min(pf[u][i].second, pf[v][j].second));
        i++; j++;
      }
      else if (pf[u][i].first < pf[v][j].first) {
        i++;
      }
      else {
        j++;
      }
    }
  }

  // compute max flow
  cout << d.max_flow(SOURCE, SINK) << endl;
}

int main() {
  solve();
  return 0;
}
