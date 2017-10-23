#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;

  vector<vi> indices(55);
  vi nums(N);

  for (int i=0;i<N;i++) {
    cin >> nums[i];
    indices[nums[i]].push_back(i);
  }

  for (int i=0;i<N;i++) {
    int num = nums[i];
    int best = -1;
    for (int j=num+1;j<=50;j++) {
      auto it = lower_bound(indices[j].begin(), indices[j].end(), i+1);
      if (it != indices[j].end())
        if (best == -1 || *it < best)
          best = *it;
    }
    if (best == -1) cout << -1;
    else cout << nums[best];
    cout << " \n"[i==N-1];
  }



  return 0;
}
