#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void solve(string expression) {
  stack<int> open;
  vector<pii> brackets;
  vi openClosed(1000,-1);
  for (int i=0;i<(int)expression.size();i++) {
    char c = expression[i];
    if (c == '(') {
      open.push(i);
    } else if (c == ')') {
      int L = open.top(); open.pop();
      openClosed[L] = i;
      brackets.push_back(make_pair(L, i));
    }
  }

  vector<bool> isIn(1000, true), isDeleted(brackets.size(), false);

  // step 1
  int L = 0, R = expression.size()-1;
  while (!brackets.empty()) {
    pii outerBracket = brackets.back();
    if (outerBracket.first == L && outerBracket.second == R) {
      isIn[L] = false; isIn[R] = false;
      brackets.pop_back();
      isDeleted.pop_back();
      L++;
      R--;
    } else break;
  }

  // step 2
  for (int i=(int)brackets.size()-1;i>=0;i--) {
    if (!isDeleted[i]) {
      pii curBracket = brackets[i];
      int curL, curR;
      curL = curBracket.first; curR = curBracket.second;
      char left = '_', right = '_';
      for (int j=curL-1;j>=0;j--) {
        if (isIn[j]) {
          left = expression[j];
          break;
        }
      }
      for (int j=curR+1;j<R+1;j++) {
        if (isIn[j]) {
          right = expression[j];
          break;
        }
      }

      // cerr << curL << " " << curR << endl;
      // cerr << left << " " << right << endl;

      if ((left == '+' && right == '+') ||
          (left == '+' && right != '(') ||
          (right == '+' && left != ')') ||
          (left == '(' && right == ')')
         ) {
        isIn[curL] = false; isIn[curR] = false;
        isDeleted[i] = true;
      }
    }
  }

  // step 3
  for (int i=0;i<(int)brackets.size();i++) {
    if (!isDeleted[i]) {
      pii curBracket = brackets[i];
      int curL, curR;
      curL = curBracket.first; curR = curBracket.second;

      int j = curL+1;
      bool plusAppeared = false;
      while (j<curR) {
        if (expression[j] == '(' && isIn[j]) j = openClosed[j];
        else if (expression[j] == '+') {
          plusAppeared = true;
          break;
        }
        j++;
      }

      // cerr << curL << " " << curR << endl;
      // cerr << plusAppeared << endl;

      if (!plusAppeared) {
       isIn[curL] = false; isIn[curR] = false;
       isDeleted[i] = true;
      }
    }
  }

  for (int i=0;i<(int)expression.size();i++) {
    if (isIn[i]) cout << expression[i];
  }
  cout << endl;
}

int main() {
  string line;
  while (getline(cin, line)) {
    solve(line);
  }
  return 0;
}
