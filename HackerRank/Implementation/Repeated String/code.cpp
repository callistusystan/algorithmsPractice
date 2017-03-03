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
#define printArray(array, a, b) for (int i=a;i<b;i++) { cout << array[i] << " "; } cout << endl;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
int even(int n) { return !(n%2); }
int odd(int n) { return n%2; }
const db pi=3.14159265358979323846264338327950288L;

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    string s;
    long long n;

    cin >> s >> n;

    long long nAInS = count(s.begin(), s.end(), 'a');
    long long lenS = s.size();

    long long nA = (n/lenS)*nAInS;
    long long remaining = n - (n/lenS)*lenS;

    for (int i=0;i< remaining;i++){
        if (s[i] == 'a'){
            nA++;
        }
    }

    cout << nA << endl;

    return 0;
}
