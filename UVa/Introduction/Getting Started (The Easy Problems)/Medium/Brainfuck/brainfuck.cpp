#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
  return (a%b+b)%b;
}

int main() {
  int T;
  cin >> T;

  ws(cin);
  for (int t=1;t<=T;t++) {
    string line;
    cin >> line;

    vector<int> array(100,0);
    int pointer = 0;

    for (int i=0;i<(int)line.length();i++) {
      switch (line[i]) {
        case '>':
          pointer++;
          break;
        case '<':
          pointer--;
          break;
        case '+':
          array[pointer]++;
          break;
        case '-':
          array[pointer]--;
          break;
        case '.':
          break;
      }
      pointer = mod(pointer, 100);
      array[pointer] = mod(array[pointer], 256);
    }

    cout << "Case " << t << ":";

    for (int i=0;i<100;i++) {
      printf(" %02X", array[i]);
    }
    cout << endl;
  }


  return 0;
}
