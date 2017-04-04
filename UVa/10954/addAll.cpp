#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N, N) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i=0;i<N;i++) {
      int num;
      cin >> num;
      q.push(num);
    }

    long long cost = 0;
    while (q.size() >= 2) {
      int num1, num2;
      num1 = q.top(); q.pop();
      num2 = q.top(); q.pop();
      cost += num1+num2;
      q.push(num1+num2);
    }
    cout << cost << endl;
  }
  return 0;
}
