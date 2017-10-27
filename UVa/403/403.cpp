#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

string C5[][5] = {
    {".***..", "*...*.", "*****.", "*...*.", "*...*."}, // A
    {"****..", "*...*.", "****..", "*...*.", "****.."}, // B
    {".****.", "*...*.", "*.....", "*.....", ".****."}, // C
    {"****..", "*...*.", "*...*.", "*...*.", "****.."}, // D
    {"*****.", "*.....", "***...", "*.....", "*****."}, // E
    {"*****.", "*.....", "***...", "*.....", "*....."}, // F
    {".****.", "*.....", "*..**.", "*...*.", ".***.."}, // G
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."}, // H
    {"*****.", "..*...", "..*...", "..*...", "*****."}, // I
    {"..***.", "...*..", "...*..", "*..*..", ".**..."}, // J
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."}, // K
    {"*.....", "*.....", "*.....", "*.....", "*****."}, // L
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."}, // M
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."}, // N
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."}, // O
    {"****..", "*...*.", "****..", "*.....", "*....."}, // P
    {".***..", "*...*.", "*...*.", "*..**.", ".****."}, // Q
    {"****..", "*...*.", "****..", "*..*..", "*...*."}, // R
    {".****.", "*.....", ".***..", "....*.", "****.."}, // S
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."}, // T
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."}, // U
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."}, // V
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."}, // W
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."}, // X
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."}, // Y
    {"*****.", "...*..", "..*...", ".*....", "*****."}, // Z
    {"......", "......", "......", "......", "......"}, // BLANK
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  vector<string> page(60, string(60, '.'));

  string line;
  while (getline(cin ,line)) {
    if (line == ".EOP") break;
    stringstream ss(line);

    string command, F, S;
    int R, C;
    ss >> command >> F >> R;
    if (command == ".P") {
      ss >> C;
      getline(ss, S);
      S = S.substr(2, (int)S.size()-2);
    } else {
      getline(ss, S);
      S = S.substr(2, (int)S.size()-2);
    }
    cout << command << " " << S << endl;
  }

  for (string s: page) {
    cout << s << endl;
  }

  return 0;
}
