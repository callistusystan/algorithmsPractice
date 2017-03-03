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
    vector<int> v(5);

    for (int i=0;i<5;i++){
        cin >> v[i];
    }

    sort(begin(v),end(v));

    long long min=0,max=0;
    for (int i=0;i<4;i++){
        min += v[i];
        max += v[i+1];
    }

    cout << min << " " << max << endl;
    return 0;
}
