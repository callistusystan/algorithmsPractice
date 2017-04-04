#include <bits/stdc++.h>

using namespace std;

class Contestant {
  public:
    bool isParticipating;
    int id;
    int nSolved;
    int time;
    vector<bool> done;
    vector<int> tried;
};

bool myCMP(Contestant a, Contestant b) {
  if (a.nSolved != b.nSolved) return a.nSolved > b.nSolved;
  if (a.time != b.time) return a.time < b.time;
  return a.id < b.id;
}

void initContestant(Contestant &c, int id) {
  c.id = id;
  c.isParticipating = false;
  c.nSolved = 0;
  c.time = 0;
  c.done = vector<bool>(10,false);
  c.tried = vector<int>(10,0);
}

int main() {
  int T;
  cin >> T;
  string line;
  getline(cin, line);
  getline(cin, line);
  while (T--) {
    vector<Contestant> contestants(101);
    for (int i=0;i<101;i++) {
      initContestant(contestants[i], i);
    }

    while (getline(cin, line), line != "") {
      istringstream iss(line);
      int C, P, T;
      char L;
      iss >> C >> P >> T >> L;

      contestants[C].isParticipating = true;
      if (L == 'C' && !contestants[C].done[P]) {
        contestants[C].done[P] = true;
        contestants[C].nSolved++;
        contestants[C].time += T + contestants[C].tried[P]*20;
      } else if (L == 'I' && !contestants[C].done[P]) {
        contestants[C].tried[P]++;
      }
    }
    sort(contestants.begin(), contestants.end(), myCMP);

    for (int i=0;i<101;i++) {
      Contestant c =contestants[i];
      if (c.isParticipating)
        printf("%d %d %d\n", c.id, c.nSolved, c.time);
    }
    if (T) cout << endl;
  }
}
