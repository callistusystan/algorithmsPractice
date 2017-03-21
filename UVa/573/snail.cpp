#include <bits/stdc++.h>

using namespace std;

int main() {
  double H, U, D, F;
  while (cin>>H>>U>>D>>F, H || U || D || F) {
    int day=1;
    double u=U, h=0;
    while (true) {
      // cout << day << " " << h << " " << u << " " << h + u << " " <<  h + u - D <<endl;
      // climb
      if (u > 0) {
        h += u;
        if (h > H) break;
      }

      // slide down
      h -= D;
      if (h<0) {
        break;
      }
      u -= F/100.0*U;
      day++;
    }

    if (h > H) {
      cout << "success on day " << day;
    } else {
      cout << "failure on day " << day;
    }
    cout << endl;
  }
  return 0;
}
