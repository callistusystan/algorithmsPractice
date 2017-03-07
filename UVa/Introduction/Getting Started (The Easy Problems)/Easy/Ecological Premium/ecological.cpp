#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int size, nAnimals, envScore;

  while (N--) {
    int F;
    cin >> F;
    double sum = 0;
    while (F--) {
      cin >> size >> nAnimals >> envScore;

      double avg = (double)size/nAnimals;
      double premium = avg * envScore *nAnimals;
      sum += premium;
    }

    cout << (int)sum << endl;
  }
  return 0;
}
