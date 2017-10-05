#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<ll, int> lli;
typedef vector<lli> vlli;

template < typename T> struct PushRelabel {
struct edge { int to; T flow , cap ; }; T INF = numeric_limits <T >:: max ();
int n, m, s, t, max_bkt ; vi h, inq , num_h , cur_e ; vvi g, bkt ;
vector <edge > edges ; vector <T> ex;
void gap_heuristic ( int k) {
for (int u = 0; u < n; u ++) if (u != s && h[u] > k && h[u] <= n) {
num_h [h[u]] --; cur_e [u] = 0;
if ( inq [u]) bkt [h[u ]]. clear (); bkt[n +1]. push_back (u);
h[u] = n +1; num_h [h[u ]]++;
if (h[u] > max_bkt ) max_bkt = h[u];
}
}
void push ( int u, int v, int id) {
T tmp = min (ex[u], edges [id ]. cap - edges [id ]. flow );
ex[u] -= tmp , ex[v] += tmp , edges [id ]. flow += tmp , edges [id ^1]. flow -= tmp ;
}
int relabel ( int u) {
int minH = 2 * n;
for (int id : g[u]) if ( edges [id ]. flow < edges [id ]. cap)
minH = min (minH , h[ edges [id ]. to ]);
return 1 + minH ;
}
void discharge ( int u) {
inq [u] = 0;
while (ex[u] > 0) {
for (; cur_e [u] < ( int) g[u]. size (); cur_e [u ]++) {
int id = g[u][ cur_e [u]], v = edges [id ]. to;
if ( edges [id ]. cap == edges [id ]. flow ) continue ;
if (h[u] == h[v ]+1) {
push (u, v, id);
if ( inq [v] == 0 && v != s && v != t) {
bkt [h[v ]]. push_back (v); inq [v] = 1;
if (h[v] > max_bkt ) max_bkt = h[v];
}
}
if (ex[u] == 0) break ; // remain at cur_e
}
if (ex[u] > 0) {
int prev_h = h[u]; num_h [h[u]] --; h[u] = relabel (u);
num_h [h[u ]]++; cur_e [u] = 0;
if ( num_h [ prev_h ] == 0 && prev_h <= n - 1) gap_heuristic ( prev_h );
}
}
}
PushRelabel ( int n) : n(n), m(0) , max_bkt (0) , inq (n), num_h (2* n),
cur_e (n), g(n), bkt (2* n), ex(n) {
num_h [0] = n - 1; num_h [n] = 1;
}
int add_edge ( int u, int v, int cap) {
g[u]. push_back (m ++) ; g[v]. push_back (m ++) ;
edges . push_back ({v, 0, cap }); edges . push_back ({u, 0, 0}) ;
return m -2;
}
edge & get_edge ( int i) { return edges [i]; } // get a reference to the i’th edge
T max_flow ( int _s , int _t) {
s = _s; t = _t; h. assign (n, 0); h[s] = n;
for (int id : g[s]) {
int u = edges [id ]. to; ex[u] += edges [id ]. cap ;
if ( inq [u] == 0 && u != s && u != t) bkt [0]. push_back (u), inq [u] = 1;
edges [id ]. flow += edges [id ]. cap ; edges [id ^1]. flow -= edges [id ]. cap ;
} // if ( max_bkt < n) [ change if edge flow not needed ]
while ( max_bkt >= 0) if (! bkt [ max_bkt ]. empty ()) {
int u = bkt [ max_bkt ]. back (); bkt[ max_bkt ]. pop_back (); discharge (u);
} else max_bkt --;
return ex[t];
}
};

void solve() {
  int N, M, S, t;
  cin >> N >> M >> S >> t;
  S--; t--;

  PushRelabel<long long> d(N);

  map<ii, ll> edges;
  for (int i=0;i<M;i++) {
    int u,v; ll c; cin >> u >> v >> c;
    u--; v--;
    if (u != v && c > 0)
      edges[{u,v}] += c;
  }

  for (auto it = edges.begin();it != edges.end();it++) {
    ii e = it->first;
    ll c = it->second;
    d.add_edge(e.first, e.second, c);
  }

  cout << d.max_flow(S, t) << endl;
}

int main() {
  solve();
  return 0;
}
