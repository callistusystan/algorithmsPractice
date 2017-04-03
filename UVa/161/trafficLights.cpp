#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    vector<int> cycle;
    int time;
    while (cin >> time, time) {
      cycle.push_back(time);
    }

    int N = cycle.size();

    if (N == 0) break;


    vector<char> color(N, 'G');
    vector<int> timeElapsed(N, 0);

    bool hasOrangeAppeared = false;

    int i;
    for (i=1;i<=5*60*60;i++) {
      // update lights
      for (int j=0;j<N;j++) {
        timeElapsed[j]++;
        if (color[j] == 'G' && timeElapsed[j] == cycle[j]-5) {
          color[j] = 'O';
          hasOrangeAppeared = true;
        }

        if (timeElapsed[j] == cycle[j]) {
          timeElapsed[j] = 0;
          if (color[j] == 'R') color[j] = 'G';
          else color[j] = 'R';
        }
      }

      bool allGreen = true;
      for (char c : color) {
        if (c != 'G') {
          allGreen = false;
          break;
        }
      }

      if (hasOrangeAppeared && allGreen) {
        break;
      }
    }

    if (i > 5*60*60) cout << "Signals fail to synchronise in 5 hours" << endl;
    else printf("%02d:%02d:%02d\n", i/(60*60), (i/60)%60, i%60);
  }
  return 0;
}
