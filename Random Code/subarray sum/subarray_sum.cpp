#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

/*
 * Making use of the fact:-
 *   S_ij = P[j] - P[i-1]
 *   P[j] = P[i-1] + S_ij
 *
 * Strategy: Loop through each i
 * See if there is a j such that P[j] = P[i-1] + S_ij
 */
int main() {
  int N; ll X; cin >> N >> X;
  vector<ll> A(N), P(N);
  unordered_map<int, ll> M;
  for (int i=0;i<N;i++) {
    cin >> A[i];
    P[i] = A[i];
    if (i) P[i] += P[i-1];
    M[P[i]] = max(M[P[i]], i);
  }

  for (int i=0;i<N;i++) {
    int left = 0;
    if (i > 0) left = P[i-1];
    if (M.count(left + X) && M[left+X] >= i) {
      cout << i << " " << M[left+X] << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
