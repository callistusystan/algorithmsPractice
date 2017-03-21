#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  while (getline(cin, line), line != "Game Over") {
    int ans = 0;
    vector<int> score;

    for (int i=0;i<(int)line.size();i++) {
      if (line[i] == ' ') continue;

      if (line[i] == 'X') score.push_back(10);
      else if (line[i] == '/') score.push_back(10 - score[score.size()-1]);
      else score.push_back(line[i] - '0');
    }

    int cur = 0;
    for (int frame=0;frame<10;frame++) {
      if (score[cur] == 10){
        ans += 10 + score[cur+1] + score[cur+2];
        cur++;
      } else if (score[cur] + score[cur+1] == 10) {
        ans += 10 + score[cur+2];
        cur += 2;
      } else {
        ans += score[cur]+score[cur+1];
        cur += 2;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
