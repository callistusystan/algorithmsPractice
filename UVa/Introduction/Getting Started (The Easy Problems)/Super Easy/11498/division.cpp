#include <bits/stdc++.h>

using namespace std;

int main() {
  int K;
  while (cin >> K, K) {
      int N, M;
      cin >> N >> M;

      for (int i=0;i<K;i++) {
        int x, y;
        cin >> x >> y;
        if (x==N || y == M) {
          cout << "divisa";
        } else if (x < N && y > M) {
          cout << "NO";
        } else if (x > N && y > M) {
          cout << "NE";
        } else if (x > N && y < M) {
          cout << "SE";
        } else {
          cout << "SO";
        }
        cout << endl;
      }
    }
  return 0;
}
