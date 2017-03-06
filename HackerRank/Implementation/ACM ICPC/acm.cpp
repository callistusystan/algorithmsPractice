// https://www.hackerrank.com/challenges/acm-icpc-team

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<string> persons(N);

  for (int i=0;i<N;i++) {
    cin >> persons[i];
  }

  int maxTopics=0, totalTeams=0;

  for (int i=0;i<N;i++) {
    for (int j=i+1;j<N;j++) {
      int thisTeamTopics =0;
      for (int k=0;k<M;k++) {
        if (persons[i][k] == '1' || persons[j][k] == '1') {
          thisTeamTopics++;
        }
      }
      if (thisTeamTopics > maxTopics) {
        maxTopics = thisTeamTopics;
        totalTeams = 0;
      }

      if (thisTeamTopics == maxTopics)
        totalTeams++;
    }
  }

  cout << maxTopics << endl;
  cout << totalTeams << endl;
  return 0;
}
