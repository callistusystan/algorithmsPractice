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
    int T;
    cin >> T;

    while (T--){
        int N, K;
        cin >> N >> K;

        vector<int> arrival(N);

        int n=0,a;

        for (int i=0;i<N;i++){
            cin >> a;
            if (a<=0) {
                n++;
            }
        }
        if (n>=K){
            cout << "NO";
        }
        else {
            cout << "YES";
        }

        cout << endl;


    }
    return 0;
}
