#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
  int N, P, t=1;
  while (cin>>N>>P, N || P) {
    ws(cin);
    for (int i=0;i<N;i++) {
      string requirement;
      getline(cin, requirement);
    }

    string bestProposal;
    int bestR = -1;
    double bestD = 2000000000;

    for (int i=0;i<P;i++) {
      string proposal;
      getline(cin, proposal);

      double D;
      int R;

      cin >> D >> R;

      if (R > bestR) {
        bestProposal = proposal;
        bestR = R;
        bestD = D;
      } else if (R == bestR && D < bestD) {
        bestProposal = proposal;
        bestR = R;
        bestD = D;
      }

      ws(cin);
      for (int j=0;j<R;j++) {
        string requirement;
        getline(cin, requirement);
      }
    }

    if (t>1) cout << endl;
    cout << "RFP #" << t++ << endl;
    cout << bestProposal << endl;
  }
  return 0;
}
