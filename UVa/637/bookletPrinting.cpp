#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N, N) {
    printf("Printing order for %d pages:\n", N);

    int lo = 1, hi = ceil((double)N/4)*4;
    for (int i=1;i<=ceil((double)N/4);i++) {
      // first sheet
      printf("Sheet %d, front: ", i);
      if (hi <= N) cout << hi;
      else cout << "Blank";
      cout << ", ";

      if (lo <=N) cout << lo;
      else cout << "Blank";
      cout << endl;
      lo++; hi--;

      // second sheet
      if (lo <= N) {
        printf("Sheet %d, back : ", i);
        if (lo <= N) cout << lo;
        else cout << "Blank";
        cout << ", ";
        if (hi <= N) cout << hi;
        else cout << "Blank";
        cout << endl;
        lo++; hi--;
      }
    }
  }
  return 0;
}
