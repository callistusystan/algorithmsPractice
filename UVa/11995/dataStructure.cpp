#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N) {
    stack<int> myS;
    queue<int> myQ;
    priority_queue<int> myPQ;

    bool isS, isQ, isPQ;
    isS = isQ = isPQ = true;

    vector<pair<int, int>> actions;

    while (N--) {
      int num1, num2;
      cin >> num1 >> num2;
      actions.push_back(make_pair(num1,num2));
    }

    for (pair<int, int> action : actions) {
      int num1 = action.first;
      int num2 = action.second;

      if (num1 == 1) {
        myS.push(num2);
        myQ.push(num2);
        myPQ.push(num2);
      } else {
        if (myS.size() == 0) {
          isS = false; isQ = false; isPQ = false;
          break;
        }
        if (myS.top() != num2) isS = false;
        if (myQ.front() != num2) isQ = false;
        if (myPQ.top() != num2) isPQ = false;
        myS.pop(); myQ.pop(); myPQ.pop();
      }
    }

    if (isS && !isQ && !isPQ) cout << "stack";
    else if (!isS && isQ && !isPQ) cout << "queue";
    else if (!isS && !isQ && isPQ) cout << "priority queue";
    else if (!isS && !isQ && !isPQ) cout << "impossible";
    else cout << "not sure";
    cout << endl;
  }
  return 0;
}
