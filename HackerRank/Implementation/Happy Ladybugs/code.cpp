// https://www.hackerrank.com/challenges/happy-ladybugs

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

    int g;
    cin >> g;
    while (g--){
        int n;
        string b;

        cin >> n >> b;
        vi appeared(26,0);
        bool hasUnderscore = false;

        for (int i=0;i<b.size();i++){
            if ('A' <= b[i] && b[i] <= 'Z'){
                appeared[b[i]-'A']++;
            }
            else {
                hasUnderscore = true;
            }
        }

        // check if length = 1
        if (b.size() == 1){
            // is underscore
            if (hasUnderscore){
                cout << "YES";
            }
            else {
                cout << "NO";
            }
            cout << endl;
        }

        // if has underscore
        else if (hasUnderscore){
            // check if any appears only once, false
            bool appearOnce = false;
            for (int i=0;i<26;i++){
                if (appeared[i] == 1){
                    appearOnce = true;
                    break;
                }
            }
            if (appearOnce) {
                cout << "NO";
            }
            else {
                cout << "YES";
            }
            cout << endl;
        }
        else {
            // check if all adjacent
            bool adjacent = true;
            // check edge
            if (b[0] != b[1]){
                adjacent = false;
            }
            else if (b[b.size()-1] != b[b.size()-2]) {
                adjacent = false;
            }
            else {
                // check with previous
                char prev = b[1];
                int n = 2;
                for (int i=2;i<=b.size()-2;i++){
                    if (b[i] != prev) {
                        if (n == 1){
                            adjacent = false;
                            break;
                        }
                        else {
                            prev = b[i];
                            n = 1;
                        }
                    }
                    else {
                        n++;
                    }
                }
            }

            if (adjacent){
                cout << "YES";
            }
            else {
                cout << "NO";
            }
            cout << endl;
        }
    }

    return 0;
}
