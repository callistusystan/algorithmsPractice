#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

string S;
int N;

ll rec(int id, string clip) {
  cout << id << " " << clip << endl;
  if (id == N) return 0;
  if (id > N) return LLONG_MAX/2;

  ll opt1 = rec(id+1, clip);
  ll opt2 = LLONG_MAX/2;
  for (int i=0;i<id;i++) {
    for (int j=i;j<id;j++) {
      opt2 = min(opt2, rec(id, S.substr(i,j-i+1)));
    }
  }

  ll opt3 = LLONG_MAX/2;
  bool possible = true;
  if (id + (int)clip.length() <= N){
    for (int i=0;i<(int)clip.length();i++) {
      cerr << "S: ";
      cerr << S[id+i] << endl;
      cerr << "CLIP: ";
      cerr << clip[i] << endl;
      if (S[id+i] != clip[i]) {
        possible = false;
        break;
      }
    }
  }
  if (possible) {
    opt3 = min(opt3, rec(id+clip.length(), clip));
  }

  vector<ll> ans = {opt1, opt2, opt3};

  return 1 + *min_element(ans.begin(), ans.end());
}

void solve() {
  cin >> S; N = S.length();
  cout << rec(0, "") << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
