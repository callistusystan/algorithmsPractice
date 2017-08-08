#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void sumItUp(int cur, int sum, vi &curSol, set<vi> &allSols, int T, vi &nums) {
  if (sum == T) allSols.insert(curSol);
  else if (cur == (int)nums.size() || sum > T) return;
  else {
    // try including this in sum
    curSol.push_back(nums[cur]);
    sumItUp(cur+1, sum+nums[cur], curSol, allSols, T, nums);
    curSol.pop_back();

    // try not including this in sum
    sumItUp(cur+1, sum, curSol, allSols, T, nums);
  }
}

void solve(int T, int N) {
  vi nums(N);
  for (int i=0;i<N;i++) cin >> nums[i];

  set<vi> allSols;
  vi curSol;
  sumItUp(0, 0, curSol, allSols, T, nums);
  printf("Sums of %d:\n", T);
  if (allSols.size()) {
    for (auto rit = allSols.rbegin();rit != allSols.rend(); rit++) {
      vi sol = *rit;
      for (int i=0;i<(int)sol.size();i++) {
        if (i) cout << "+";
        cout << sol[i];
      }
      cout << endl;
    }
  } else {
    cout << "NONE" << endl;
  }
}

int main() {
  int T, N;
  while (cin >> T >> N, T || N) {
    solve(T, N);
  }
  return 0;
}
