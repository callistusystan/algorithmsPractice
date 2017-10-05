#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

double EPS = 1e-9;
int N;
int L;

vector<int> points;

int main() {
  cin >> N >> L;
  points.resize(N);
  for (int i=0;i<N;i++) {
    cin >> points[i];
  }
  sort(points.begin(), points.end());

  double r = max(points[0], L-points[N-1]);

  for (int i=1;i<N;i++) {
    double d = points[i]-points[i-1];
    r = max(r, d/2);
  }

  printf("%.10lf\n", r);

  return 0;
}
