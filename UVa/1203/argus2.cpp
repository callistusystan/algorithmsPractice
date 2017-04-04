#include <bits/stdc++.h>

using namespace std;

class Instruction {
  public:
    int num;
    int nextRun;
    int period;

    Instruction(int aNum, int aNextRun, int aPeriod) {
      num = aNum;
      nextRun = aNextRun;
      period = aPeriod;
    }
};

class Compare {
  public:
    bool operator() (Instruction a, Instruction b) {
      if (a.nextRun != b.nextRun) return a.nextRun > b.nextRun;
      return a.num > b.num;
    }
};


int main() {
  string instruction;
  priority_queue<Instruction, vector<Instruction>, Compare> myPQ;
  while (cin >> instruction, instruction != "#") {
    int qNum, period;
    cin >> qNum >> period;

    Instruction i(qNum, period, period);

    myPQ.push(i);
  }

  int N;
  cin >> N;

  while (N--) {
    Instruction top = myPQ.top();
    cout << top.num << endl;
    myPQ.pop();

    Instruction newI(top.num, top.nextRun+top.period, top.period);
    myPQ.push(newI);
  }
  return 0;
}
