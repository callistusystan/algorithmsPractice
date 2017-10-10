#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N;

template < typename T> vector <T> lis ( vector <T >& v) {
  int n = v. size () , len = 0; vi tail (n), prev (n); T val[n];
  for (int i =0; i < n; i++) { // Change to upper_bound for non - decreasing
    int pos = lower_bound (val , val + len , v[i]) - val ;
    len = max (len , pos + 1) , prev [i] = ( pos > 0 ? tail [pos - 1] : -1);
    tail [ pos ] = i; val[ pos ] = v[i];
  }
  vector <T> res( len);
  for (int i = tail [ len - 1]; i >= 0; i = prev [i]) res [--len] = v[i];
  return res;
}

void solve() {
  int num; vi nums;
  while (cin >> num) {
    nums.push_back(num);
  }
  N = nums.size();

  vi ans = lis(nums);

  printf("%d\n-\n", (int)ans.size());
  reverse(ans.begin(), ans.end());
  for (int i=(int)ans.size()-1;i>=0;i--)
    cout << ans[i] << endl;;
}

int main() {
  solve();
  return 0;
}
