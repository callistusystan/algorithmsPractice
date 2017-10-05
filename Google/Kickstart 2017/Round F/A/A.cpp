#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

/*
1 *4 3 2 -> false

1 *3 2 | 4 -> false

*1 2 | 3 4 -> false

1 | 2 | 3 4 -> false
*/

int N;
vi A,B,C;

bool notAllWorse(int i, int j) {
  int E = j-i+1;
  if (E <= 1) return false;
  else {
    int P_index = i+(E-1)/2;
    // cerr << A[P_index] << " is pivot" << endl;
    int pivot = A[P_index];
    int cntB,cntC; cntB=cntC=0;
    for (int k=i;k<=j;k++) {
      if (k == P_index) continue;
      if (A[k] <= pivot) {
        B[cntB++] = A[k];
      } else {
        C[cntC++] = A[k];
      }
    }
    if (cntB && cntC) return true;
    for (int k=0;k<cntB;k++) {
      A[k] = B[k];
    }
    A[cntB] = pivot;
    for (int k=0;k<cntC;k++) {
      A[cntB+1+k] = C[k];
    }
    // for (int num : A) {
    //   cerr << num << " ";
    // } cerr << endl;
    if (cntB == 0) { // P cntC
      if (notAllWorse(i+1,j)) return true;
      return false;
    }
    else { // (cntC == 0)
      if (notAllWorse(i,j-1)) return true;
      return false;
    }
  }
}

void solve() {
  cin >> N;
  A.resize(N);
  B.resize(N);
  C.resize(N);
  for (int i=0;i<N;i++) cin >> A[i];

  if (notAllWorse(0,N-1)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
