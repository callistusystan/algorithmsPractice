//https://www.hackerrank.com/challenges/equality-in-a-array

#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> count(100,0);

  int N;
  cin >> N;

  int num, maxCount = 0;
  for (int i=0;i<N;i++) {
    cin >> num;
    count[num]++;
    maxCount = max(maxCount, count[num]);
  }
  cout << N-maxCount << endl;
  return 0;
}
