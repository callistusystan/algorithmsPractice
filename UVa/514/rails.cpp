#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N, N) {
    vector<int> coaches(N);
    while (cin >> coaches[0], coaches[0]) {
      for (int i=1;i<N;i++) cin >> coaches[i];

      stack<int> myStack;
      bool canDo = true;
      int i = 1, pointer = 0;
      while (pointer < N) {
        if (i <=N && (myStack.empty() || myStack.top() != coaches[pointer])) {
          myStack.push(i);
          i++;
        } else if (myStack.top() == coaches[pointer]) {
          myStack.pop();
          pointer++;
        } else {
          canDo = false;
          break;
        }
      }

      if (canDo) cout << "Yes";
      else cout << "No";
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
