#include <bits/stdc++.h>

using namespace std;

int main() {
  int loanDuration, nRecords;
  double downPayment, loanAmount;

  vector<double> records(105);
  while (cin >> loanDuration >> downPayment >> loanAmount >> nRecords, loanDuration >= 0) {
    for (int i=0;i<nRecords;i++) {
      int month;
      double dep;
      cin >> month >> dep;

      for (int j=month;j< 105;j++)
        records[j] = dep;
    }

    int now = 0;
    double monthlyPayment = loanAmount/loanDuration;
    double curVal = (loanAmount + downPayment) * (1.0-records[0]);
    double curLoan = loanAmount;

    while (curVal < curLoan) {
      now++;
      curLoan -= monthlyPayment;
      curVal *= (1.0 - records[now]);
    }

    printf("%d %s\n", now, (now == 1) ? "month" : "months");
  }
  return 0;
}
