#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void solve(string line) {
  stack<int> open;
  vector<pii> brackets;
  for (int i=0;i<(int)line.size();i++) {
    char c = line[i];
    if (c == '(') {
      open.push(i);
    } else if (c == ')') {
      int L = open.top(); open.pop();
      brackets.push_back(make_pair(L, i));
    }
  }
  int nBrackets = brackets.size(), N = line.size();

  vector<bool> isIn(1000, true);
  // step 1: remove redundant outer brackets, e.g. $((()))$ => $()$
  for (int i=nBrackets-1;i>=0;i--) {
    pii outerBracket = brackets[i];
    int curL, curR;
    curL = outerBracket.first; curR = outerBracket.second;

    char left = '_', right = '_';
    // get left neighbour
    for (int j=curL-1;j>=0;j--) {
      if (isIn[j]) {
        left = line[j];
        break;
      }
    }
    // get right neighbour
    for (int j=curR+1;j<N;j++) {
      if (isIn[j]) {
        right = line[j];
        break;
      }
    }

    // check if its a useless outer bracket being a bracket -katie 2017
    if ((left == '_' && right == '_') || (left == '(' && right == ')')) {
      isIn[curL] = false; isIn[curR] = false;
    }
  }

  // step 2: remove brackets next to +, e.g. +($)+ => +$+,
  // +($) => +$ iff not part of a multiplication
  for (int i=nBrackets-1;i>=0;i--) {
    pii outerBracket = brackets[i];
    int curL, curR;
    curL = outerBracket.first; curR = outerBracket.second;

    if (!isIn[curL]) continue;

    char left = '_', right = '_';
    // get left neighbour
    for (int j=curL-1;j>=0;j--) {
      if (isIn[j]) {
        left = line[j];
        break;
      }
    }
    // get right neighbour
    for (int j=curR+1;j<N;j++) {
      if (isIn[j]) {
        right = line[j];
        break;
      }
    }

    // check if its a useless outer bracket being a bracket -katie 2017
    if ((left == '+' && right == '+') ||
        (left == '+' && right != '(' && !isalpha(right)) ||
        (right == '+' && left != ')' && !isalpha(left))
       ) {
      isIn[curL] = false; isIn[curR] = false;
    }
  }

  // step 3: remove () if no + inside, e.g. (abc) => abc
  for (int i=nBrackets-1;i>=0;i--) {
    pii outerBracket = brackets[i];
    int curL, curR;
    curL = outerBracket.first; curR = outerBracket.second;
    if (!isIn[curL]) continue;

    bool hasPlus = false;
    int j = curL+1;
    while (j<curR) {
      if (isIn[j]) {
        if (line[j] == '(') {
          while (!(isIn[j] && line[j] == ')')) j++;
        } else if (line[j] == '+') hasPlus = true;
      }
      j++;
    }

    if (!hasPlus) {
      isIn[curL] = false; isIn[curR] = false;
    }
  }

  for (int i=0;i<(int)line.size();i++) {
    if (isIn[i]) cout << line[i];
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
