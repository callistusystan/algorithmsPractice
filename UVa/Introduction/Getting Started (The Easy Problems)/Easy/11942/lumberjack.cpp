#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  cout << "Lumberjacks:" << endl;
  vector<int> heights(10);
  while (N--) {
    for (int i=0;i<10;i++) {
      cin >> heights[i];
    }
    bool ascending, descending, equal;
    ascending=descending=equal = false;

    if (heights[0] == heights[9]) equal=true;
    if (heights[0] < heights[9]) ascending=true;
    if (heights[0] > heights[9]) descending=true;

    bool ordered=true;
    for (int i=1;i<10;i++) {
      if (equal && heights[i] != heights[i-1]) {
        ordered =false;
        break;
      } else if (ascending && heights[i] < heights[i-1]) {
        ordered = false;
        break;
      } else if (descending && heights[i] > heights[i-1]) {
        ordered = false;
        break;
      }
    }

    cout << (ordered ? "Ordered" : "Unordered") << endl;
  }
  return 0;
}
