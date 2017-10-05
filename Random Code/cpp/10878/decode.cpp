#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;

char getChar(string s) {
  for (int i=1;i<(int)s.size()-1;i++) {
    
  }
}

int main() {
  vector<string> lines;
  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }
  for (int i=1;i<(int)lines.size()-1;i++) {
    cout << pattern[lines[i]];
  }
  return 0;
}
