#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  vector<string> instructions(105);

  while (T--) {
    int N;
    cin >> N;

    string action;
    int index, p=0;
    for (int i=1;i<=N;i++) {
      cin >> action;
      if (action == "SAME") {
        cin >> action >> index;
        instructions[i] = instructions[index];
      } else {
        instructions[i] = action;
      }

      if (instructions[i] == "LEFT") p-=1;
      else p+=1;
    }

    cout << p << endl;
  }
  return 0;
}
