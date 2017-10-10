#include <bits/stdc++.h>

using namespace std;
#define debug (a) cerr << #a << " = " << (a) << endl ;

typedef long long ll;
typedef vector<int> vi;

double EPS = 1e-9;
int N;
double L;

vector<double> p;

bool f(double r) {
  if (r < p[0] - EPS) {
    return false;
  }

  for (int i=1;i<N;i++) {
    if (2*r < p[i]-p[i-1] - EPS) {
      return false;
    }
  }
  return r > L - p[N-1] - EPS;
}

int main() {
  cin >> N >> L;
  p.resize(N);
  for (int i=0;i<N;i++) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());

  double lo = 0, hi = L + EPS;
  while (hi - lo > EPS) {
    double mid = lo/2 + hi/2;
    if (f(mid)) hi = mid;
    else lo = mid;
  }

  printf("%.10lf\n", hi);

  return 0;
}
