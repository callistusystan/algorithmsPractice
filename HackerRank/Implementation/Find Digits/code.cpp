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
#define printArray(array) for (int i=0;i<array.size();i++) { cout << array[i] << " "; } cout << endl;
#define print2DArray(array) for (int i=0;i<array.size();i++) { for (int j=0;j<array[i].size();j++) { cout << array[i][j] << " "; } cout << endl; };
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
        int N;
        cin >> N;
        string s;
        s = to_string(N);
        int ans =0;
        F0(i,SZ(s)){
            int d_n = s[i]-'0';
            if (d_n != 0 && N%(s[i]-'0') == 0){
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
