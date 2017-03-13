#include <bits/stdc++.h>

using namespace std;

vector<string> lyrics = {"Happy","birthday", "to", "you",
                   "Happy", "birthday", "to", "you",
                   "Happy", "birthday", "to", "Rujia",
                   "Happy", "birthday", "to", "you"
                 };

int main() {
  int N;
  cin >> N;
  vector<string> names(N);
  for (int i=0;i<N;i++) cin >> names[i];

  int curPerson =0;
  for (int i=0;i<ceil((double)N/16);i++) {
    for (int j=0;j<16;j++) {
      cout << names[curPerson] << ": " << lyrics[j] << endl;
      curPerson++;
      curPerson %= N;
    }
  }

  return 0;
}
