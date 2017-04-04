#include <bits/stdc++.h>

using namespace std;

bool myCMP(tuple<int, int, int> a, tuple<int, int, int> b) {
  if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
  return get<0>(a) > get<0>(b);
}

int main() {
  string instruction;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(&myCMP)> myPQ(&myCMP);
  while (cin >> instruction, instruction != "#") {
    int qNum, period;
    cin >> qNum >> period;

    myPQ.push(make_tuple(qNum, period, period));
  }

  int N;
  cin >> N;

  while (N--) {
    tuple<int, int, int> top = myPQ.top();
    cout << get<0>(top) << endl;
    myPQ.pop();
    myPQ.push(make_tuple(get<0>(top), get<1>(top)+get<2>(top), get<2>(top)));
  }
  return 0;
}
