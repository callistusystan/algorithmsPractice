// https://www.hackerrank.com/challenges/kangaroo

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
int even(int n) { return !(n%2); }
int odd(int n) { return n%2; }
const db pi=3.14159265358979323846264338327950288L;

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x1, v1, x2, v2;
    cin >> x1 >> v1 >> x2 >> v2;

    // can x1 + t*v1 = x2 + t*v2?
    // t*(v1-v2) = x1 - x2
    // t = (x1 - x2)/(v1 - v2)
    // t must be an integer
    // thus (x1 - x2)%(v1 - v2) == 0

    if (v1 <= v2){
        cout << "NO";
    }
    else {
        if ((x1-x2)%(v1-v2) == 0){
        cout << "YES";
        }
        else {
            cout << "NO";
        }
    }

    cout << endl;

    return 0;
}
