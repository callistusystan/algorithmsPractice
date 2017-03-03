#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/the-hurdle-race

int main() {
  int N, K;
  cin >> N >> K;

  int minDrinks = 0, height;

  for (int i=0;i<N;i++) {
    cin >> height;
    if (height > K) {
      int diff = height - K;
      minDrinks += diff;
      K += diff;
    }
  }
  cout << minDrinks << endl;
  return 0;
}
