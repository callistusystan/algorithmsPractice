// https://www.hackerrank.com/challenges/divisible-sum-pairs

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
    int n, k;

    cin >> n >> k;

    vector<int> v(n);

    for (int i=0;i<n;i++){
        cin >> v[i];
    }

    int ans = 0;

    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if ((v[i]+v[j])%k == 0){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
