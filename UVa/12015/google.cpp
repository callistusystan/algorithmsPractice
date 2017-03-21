#include <bits/stdc++.h>

using namespace std;

bool f(pair<string, int> a, pair<string, int> b) {
  return a.second < b.second;
}

int main() {
  int T;
  cin >> T;
  vector<pair<string, int>> pages(15);
  for (int t=1;t<=T;t++) {
    printf("Case #%d:\n", t);
    for (int i=0;i<10;i++) {
      string url;
      int score;
      cin >> url >> score;
      pages[i] = make_pair(url, score);
    }

    sort(pages.begin(), pages.begin()+10, f);

    int bestScore = pages[9].second;
    int j = 8;
    while (pages[j].second == bestScore) {
      j--;
    }

    for (int i=j+1;i<10;i++) {
      cout << pages[i].first << endl;
    }
  }
  return 0;
}
