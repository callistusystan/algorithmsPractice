#include <bits/stdc++.h>

using namespace std;

#define x real()
#define y imag()
#define cpt const Pt&

typedef long long ll;
typedef vector<int> vi;
typedef complex <double > cpx;

double EPS = 1e-9;
bool deq ( double a, double b) { return abs (a-b)<EPS ;}

int N, M;

struct Pt : cpx {
  Pt () = default ; using cpx :: cpx ;
  Pt(cpx a) : cpx(a) {}
  double & x const { return ( double &)* this ; }
  double & y const { return (( double *) this ) [1]; }
  bool operator ==( cpt b) const { return abs (* this -b) < EPS ; }
  bool operator <( cpt b) const { return x<b.x || (x==b.x && y<b.y); }
};

bool epsless ( cpt a,cpt b) { return a.x+EPS <b.x || (deq(a.x,b.x) && a.y<b.y);}

double dot( cpt a, cpt b) { return ( conj (a) * b).x;} // Dot product
double det( cpt a, cpt b) { return ( conj (a) * b).y;} // Determinant /" Cross Product "

// Point on line segment ( including endpoints )
bool ptonseg ( cpt a, cpt b, cpt p) {
  Pt u=b-a,v=p-a;
  return a==p || b==p || ((0 < dot (u,v) && dot (u,v)<norm (u)) && deq ( det (u,v) ,0));
}

int orient ( cpt a, cpt b, cpt c) {
  double d= det (b-a,c-b);
  return d> EPS ?1:d<- EPS ? -1:0;
}

vector <Pt > convexhull ( vector <Pt > p) {
  sort (p. begin () ,p. end () ,epsless ); p. resize ( unique (p. begin () ,p. end ())-p. begin ());
  int l=0,u =0; vector <Pt > L(p),U(p);
  if (p. size () <=2) return p;
  for (Pt& i:p) {
    while (l >1 && det (i-L[l -1] ,L[l -2] -i) <-EPS ) l --;
    while (u >1 && det (i-U[u -1] ,U[u -2] -i)>EPS ) u --;
    L[l ++]= U[u ++]= i;
  }
  L. resize (l+u -2) ; copy (U. rend () -u+1,U. rend () -1,L. begin ()+l);
  return L;
}

bool point_in_convex_polygon ( const vector <Pt >& P, const Pt& p, bool boundary ) {
  int a = 1, b = ( int )P. size () -1;
  if ( ptonseg (P[a],P[0] ,p) || ptonseg (P[b],P[0] ,p))
    return boundary ; else if ( orient (P[a],P[0] ,P[b]) > 0) swap (a,b);
  if ( orient (P[a],P[0] ,p) > 0 || orient (P[b],P[0] ,p) < 0) return false ;
  while ( abs (a-b) > 1) {
    int c = (a+b) /2;
    if ( orient (P[c],P[0] ,p) > 0) b = c; else a = c;
  }
  return orient (P[b],P[a],p) < 0 || ( orient (P[b],P[a],p)==0 && boundary );
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<Pt> A(N);
  for (int i=0;i<N;i++) {
    cin >> A[i].x >> A[i].y;
  }
  cin >> M;
  vector<Pt> B(M);
  for (int i=0;i<M;i++) {
    cin >> B[i].x >> B[i].y;
  }

  vector<Pt> convexHull = convexhull(A);

  bool isPolygonIn = true;
  for (Pt p : B) {
    if (!point_in_convex_polygon(convexHull, p, false)) {
      isPolygonIn = false;
      break;
    }
  }

  if (isPolygonIn) cout << "YES";
  else cout << "NO";
  cout << endl;

  return 0;
}
