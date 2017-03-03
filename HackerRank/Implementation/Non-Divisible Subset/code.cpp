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

    int n,k;

    cin >> n >> k;

    // (a + b) divisible by k means (a+b)/k gives a whole number
    // this means a/k + b/k gives a whole number
    // this means that remainders of a/k and b/k sum to k

    vi S(n);
    vi freqRemainder(k,0);

    for (int i=0;i<n;i++){
        cin >> S[i];
        freqRemainder[S[i]%k]++;
    }

    int maxFreq = 0;
    if (freqRemainder[0] > 0){
        // we cannot have more than 2 elements divisible by k
        maxFreq = 1;
    }
    for (int i=1;i<k;i++){
        if ((i+i)%k == 0){
            if (freqRemainder[i] > 0){
                maxFreq++;
                freqRemainder[i] = 0;
            }
        }
        else {
            maxFreq += max(freqRemainder[i],freqRemainder[k-i]);
            freqRemainder[i] =0;
            freqRemainder[k-i] = 0;
        }
    }

    cout << maxFreq << endl;

    return 0;
}
