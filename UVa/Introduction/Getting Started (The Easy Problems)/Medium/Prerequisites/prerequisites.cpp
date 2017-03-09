#include <bits/stdc++.h>

using namespace std;

int main() {
  int K, M;
  while (cin >> K, K) {
    cin >> M;
    set<int> coursesTaken;
    for (int i=0;i<K;i++) {
      int course;
      cin >> course;
      coursesTaken.insert(course);
    }

    // loop m categories
    bool valid = true;
    for (int i=0;i<M;i++) {
      int nCourses, minCourses;
      cin >> nCourses >> minCourses;

      for (int j=0;j<nCourses;j++) {
        int course;
        cin >> course;
        if (coursesTaken.count(course)) {
          minCourses--;
        }
      }

      if (minCourses > 0) {
        valid = false;
      }
    }

    cout << (valid ? "yes" : "no") << endl;
  }
  return 0;
}
