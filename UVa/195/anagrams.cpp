#include <bits/stdc++.h>

using namespace std;

bool cmp(char a, char b) {
  if (isupper(a) && isupper(b))
    return a < b;
  else if (isupper(a) && islower(b)) {
    if (a == toupper(b))
      return true;
    else
      return tolower(a) < b;
  }
  else if (islower(a) && isupper(b)) {
    if (toupper(a) == b)
      return false;
    else
      return a < tolower(b);
  }
  return a < b;
}

int main() {
  int N;
  cin >> N;
  while (N--) {
    string word;
    cin >> word;
    sort(word.begin(), word.end(), cmp);

    do {
      cout << word << endl;
    } while (next_permutation(word.begin(), word.end(), cmp));
  }
  return 0;
}
