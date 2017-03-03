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
    int i,j,k;
    cin >> i >> j >> k;

    int n=0;
    for (int a=i;a<=j;a++){
        string a_str = to_string(a);
        reverse(a_str.begin(), a_str.end());
        int rev_a = stoi(a_str);

        if (abs(a-rev_a)%k == 0){
            n++;
        }
    }

    cout << n << endl;

    return 0;
}
