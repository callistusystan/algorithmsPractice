#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;

// Suffix array construction with LCP . The suffix array is built into sarray and the
// LCP into lcp. NOTE : sarray does not include the empty suffix . lcp [i] is the longest
// common prefix between the strings at sarray [i -1] and sarray [i], lcp [0] = 0.
// Complexity : O(N) or O(N log (N)) for suffix array . O(N) for LCP.
struct suffix_array {
int n; string str ; vi sarray , lcp ;
void bucket (vi& a, vi& b, vi& r, int n, int K, int off =0) {
vi c(K+1, 0);
for (int i =0; i<n; i++) c[r[a[i]+ off ]]++;
for (int i=0, sum =0; i <=K; i++) { int t = c[i]; c[i] = sum ; sum += t; }
for (int i =0; i<n; i++) b[c[r[a[i]+ off ]]++] = a[i];
}
// Create the suffix array and LCP array of the string s. ( LCP is optional )
suffix_array ( string s) : n(s. size ()), str ( move (s)) { build_sarray (); build_lcp (); }
// ------------------ OPTION 2: O(N log (N)) time suffix array -----------------------
void build_sarray () {
sarray . assign (n, 0); vi r (2*n, 0) , sa (2* n), tmp (2*n); if (n <= 1) return ;
for (int i =0; i<n; i++) r[i] = ( int ) str [i] - CHAR_MIN + 1, sa[i] = i;
for (int k =1; k<n; k *= 2) {
bucket (sa ,tmp ,r,n,max(n ,256) ,k), bucket (tmp ,sa ,r,n, max (n ,256) ,0);
tmp [sa [0]] = 1;
for (int i =1; i<n; i++) {
tmp [sa[i]] = tmp[sa[i -1]];
if ((r[sa[i]] != r[sa[i -1]]) || (r[sa[i]+k] != r[sa[i -1]+ k])) tmp[sa[i ]]++;
}
copy ( tmp . begin () , tmp . begin ()+n, r. begin ());
}
copy (sa. begin () , sa. begin ()+n, sarray . begin ());
}
// --------------------- OPTIONAL : If you need LCP array ----------------------------
void build_lcp () {
int h = 0; vi rank (n); lcp . assign (n, 0);
for (int i = 0; i < n; i ++) rank [ sarray [i]] = i;
for (int i = 0; i < n; i ++) {
if ( rank [i] > 0) {
int j = sarray [ rank [i] -1];
while (i + h < n && j + h < n && str [i+h] == str [j+h]) h ++;
lcp [ rank [i]] = h;
}
if (h > 0) h --;
}
}
// OPTIONAL : Pattern matching -- Find all occurrences of pat [j ..] in O(m log (n))
// Returns an iterator pair of the matching locations in the suffix array
struct Comp {
const string & s; int m, j;
Comp ( const string & str , int m, int j) : s(str ), m(m), j(j) { }
bool operator ()(int i, const string & p) const { return s. compare (i,m,p,j,m) < 0; }
bool operator ()( const string & p, int i) const { return s. compare (i,m,p,j,m) > 0; }
};
auto find ( const string & pat , int j=0) {
return equal_range ( sarray . begin () , sarray . end () , pat , Comp (str , pat . size () ,j));
}
};

int main() {
  int T; cin >> T;
  while (T--) {
    string s; cin >> s;
    cout << s << endl;
    suffix_array SA(s);
    for (int i=0;i<(int)SA.lcp.size();i++) {
      cout << SA.lcp[i] << endl;
    }

  }
  return 0;
}

/*
$ 0
A$ 0
ACA$ 1
ATTACA$ 1
CA$ 0
GATTACA$ 0
TACA$ 0
TTACA$ 1
*/
