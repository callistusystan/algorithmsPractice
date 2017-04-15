#include <bits/stdc++.h>

using namespace std;

string S;
int ans;

int getAns(int i, vector<stack<char>> &stacks) {
  int nStacks = stacks.size();
  char c = S[i];
  // try an existing stack
  for (int j=0;j<nStacks;j++) {
    if (c <= stacks[j].top()) {
      stacks[j].push(c);
      return 0;
    }
  }

  stack<char> newStack;
  newStack.push(c);
  stacks.push_back(newStack);
  return 1;
}

int solve() {
  vector<stack<char>> stacks;
  ans = 0;
  int N = S.size();
  for (int i = 0;i<N;i++)
    ans += getAns(i, stacks);
  return ans;
}

int main() {
  int T = 1;
  while (cin >> S, S != "end") {
    printf("Case %d: %d\n", T++, solve());
  }
  return 0;
}
