#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
string s1, s2, actions;
stack<char> chars;

void getAns(int i, int j) {
  int N = s1.size();
  // we cant have more than s2.size() letters
  if (i == N && j == N) {
    ans.push_back(actions);
    return;
  } else {
    // try to push
    if (i < N) {
      actions.push_back('i');
      chars.push(s1[i]);
      getAns(i+1, j);
      chars.pop();
      actions.pop_back();
    }
    // try to pop
    if (!chars.empty() && chars.top() == s2[j]) {
      actions.push_back('o');
      char tmp = chars.top();
      chars.pop();
      getAns(i,j+1);
      chars.push(tmp);
      actions.pop_back();
    }
  }
}

void solve() {
  // check if s1 and s2 are anagrams
  string t1 = s1, t2 = s2;
  sort(t1.begin(), t1.end()); sort(t2.begin(), t2.end());
  if (t1 != t2) return;

  ans.clear();
  actions.clear();
  chars = stack<char>();
  getAns(0, 0);

  for (string s : ans) {
    for (size_t i=0;i<s.size();i++){
      if (i) cout << " ";
      cout << s[i];
    }
    cout << endl;
  }
}

int main() {
  while (cin >> s1 >> s2) {
    cout << "[" << endl;
    solve();
    cout << "]" << endl;
  }
  return 0;
}
