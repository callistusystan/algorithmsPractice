#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define x real()
#define y imag()
#define cpt const Pt&

typedef long long ll;
typedef vector<int> vi;
typedef complex <double > cpx;

double EPS = 1e-9;
double pi = acos(-1);
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

struct Circle {
  Pt c; double r;
  bool operator ==( const Circle & b) const { return c==b.c && deq (r,b.r);}
};

pair <int ,pair <Pt ,Pt >> intersect ( const Circle & a, const Circle & b) {
Pt v=b.c-a.c; // disjoint || one inside other
if (a.r+b.r+EPS < abs (v) || abs (a.r-b.r)>abs (v)+ EPS ) return {0 ,{}};
if ( abs (v)<EPS ) return {3 ,{}};
double X=( norm (a.r)-norm (b.r)+ norm (v)) /(2.0* abs (v)), Ysq= norm (a.r)-norm (X),Y;
v/= abs(v);
if (Ysq <0 || (Y= sqrt ( Ysq ))<EPS) return {1 ,{ Pt{X ,0}* v+a.c ,{}}};
return {2 ,{ Pt{X,Y}*v+a.c,Pt{X,-Y}*v+a.c }};
}

// Find the area of the union of the given circles . Complexity : O(n^2 log (n))
double circle_union_area ( const vector < Circle >& cir ) {
int n = ( int ) cir . size (); vector <bool > ok(n, 1); double ans = 0.0;
for (int i =0; i<n; i++) for ( int j =0; j<n; j ++) if (i != j && ok[j])
if ( abs ( cir [i].c - cir [j].c)+ cir [i].r- cir [j].r < EPS ) { ok[i] = false ; break ; }
for (int i =0; i<n; i++) if (ok[i]) {
bool flag = false ; vector <pair < double ,double >> reg ;
for (int j =0; j<n; j++) if (i != j && ok[j]) {
auto p = intersect ( cir [i], cir [j]);
if (p.X < 2) continue ; else flag = true ;
auto ang1 = arg (p.Y.Y - cir[i].c), ang2 = arg (p.Y.X - cir [i].c);
if ( ang1 < 0) ang1 += 2* pi;
if ( ang2 < 0) ang2 += 2* pi;
if ( ang1 > ang2 ) reg . emplace_back (ang1 , 2* pi), reg . emplace_back (0, ang2 );
else reg . emplace_back (ang1 , ang2 );
}
if (! flag ) { ans += pi* cir [i].r* cir [i].r; continue ; }
int cnt = 1; sort ( reg . begin () , reg . end ());
for (int j =1; j <( int )reg. size (); j++)
if ( reg [cnt -1]. Y >= reg [j].X) reg[cnt -1]. Y = max ( reg [cnt -1].Y, reg[j].Y);
else reg [ cnt ++] = reg[j];
reg . emplace_back (0 ,0); reg [ cnt ] = reg [0];
for (int j =0; j<cnt; j ++) {
auto p1 = cir [i].c + polar ( cir [i].r, reg[j].Y);
auto p2 = cir [i].c + polar ( cir [i].r, reg[j +1]. X);
ans += det (p1 , p2) / 2.0;
double ang = reg [j +1]. X - reg [j].Y;
if ( ang < 0) ang += 2* pi;
ans += 0.5 * cir [i].r* cir [i].r * ( ang - sin ( ang ));
}
}
return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  double totalArea = 0;
  vector<Circle> C(2);
  for (int i=0;i<2;i++) {
    Pt p; double r;
    cin >> p.x >> p.y >> r;
    C[i].c = p;
    C[i].r = r;
    totalArea += pi*r*r;
  }
  if (C[0].r < C[1].r) swap(C[0], C[1]);

  cout << fixed << setprecision(20);
  // 0 is bigger, 1 is smaller
  // 1 in 0
  ll furthestDist = (C[0].c.x-C[1].c.x)*(C[0].c.x-C[1].c.x) + (C[0].c.y-C[1].c.y)*(C[0].c.y-C[1].c.y);
  furthestDist += C[1].r;
  if (C[0].c.x == C[1].c.x && C[0].c.y == C[1].c.y && C[0].r == C[1].r) {
    cout << pi*C[1].r*C[1].r << endl;    
  } else if ((furthestDist)*(furthestDist) <= C[0].r*C[0].r) {
    cout << pi*C[1].r*C[1].r << endl;
  } else {
    double unionArea = circle_union_area(C);
    cout << totalArea-unionArea << endl;
  }

  return 0;
}
