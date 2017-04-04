#include <bits/stdc++.h>

using namespace std;

int main() {
  string code;
  while (cin >> code, code != "#") {
    if (next_permutation(code.begin(), code.end())) {
      cout << code << endl;
    } else {
      cout << "No Successor" << endl;
    }
  }
}
