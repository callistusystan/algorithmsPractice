#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, M;
  char c;
  while (cin >> H >> c >> M, H || M) {
    if (H == 12) H = 0;
    double angleH, angleM;
    angleH = H/12.0 * 360;
    angleM = M/60.0 * 360;

    angleH += M/60.0*(360/12);

    double diff = abs(angleH - angleM);

    if (diff > 180) diff = 360-diff;
    printf("%0.3lf\n", diff);
  }
  return 0;
}
