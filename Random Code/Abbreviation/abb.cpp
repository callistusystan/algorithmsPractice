#include <bits/stdc++.h>
using namespace std;

bool isPossible(int cur, string curS, string &A, string &B) {
    // false if beyond A
    if (cur == (int)A.size()) return false;

    if (curS.size() > B.size()) return false;
    else if (curS.size() == B.size()) {
        return curS == B;
    }


    // if cur is lower case, either we take (IF MATCHES) or not take
    if (islower(A[cur])) {
        int newSize = curS.size();
        if (toupper(A[cur]) == B[newSize])
            return isPossible(cur+1, curS+(char)toupper(A[cur]), A, B) || isPossible(cur+1, curS, A, B);
        else
            return isPossible(cur+1, curS, A, B);
    }
    // if cur is upper case, no choice but to take (ONLY IF MATCHES), or start from scratch
    else {
        int newSize = curS.size();
        if (toupper(A[cur]) == B[newSize])
            return isPossible(cur+1, curS+(char)toupper(A[cur]), A, B) || isPossible(cur, "", A, B);
        else
            return isPossible(cur, "", A, B);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;
    while (Q--) {
        string A, B;
        cin >> A >> B;
        if (isPossible(0, "", A, B)) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
