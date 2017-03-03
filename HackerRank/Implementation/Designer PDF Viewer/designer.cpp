#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/designer-pdf-viewer

int main() {
  vector<int> heights(26);
  for (int i=0;i<26;i++)
    cin >> heights[i];
  string word;
  cin >> word;
  int maxHeight = 1;
  for (char c : word)
    maxHeight = max(maxHeight, heights[c-'a']);

  cout << maxHeight*word.size() << endl;
  return 0;
}
