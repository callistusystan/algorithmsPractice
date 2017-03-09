// https://www.hackerrank.com/challenges/flatland-space-stations

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
#define print2DArray(array) for (int i=0;i<array.size();i++) { for (int j=0;j<array.size();j++) { cout << array[i][j] << " "; } cout << endl };
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
int even(int n) { return !(n%2); }
int odd(int n) { return n%2; }
const db pi=3.14159265358979323846264338327950288L;

int n;
vi d(100005,(int)INFINITY);

void BFS(int s){
    d[s] = 0;
    queue<int> q;

    q.push(s);
    vector<bool> visited(n, false);

    while (!q.empty()){
        int cur = q.front();
        q.pop();
        if (cur > 0){
            if (!visited[cur-1]){
                if (d[cur] + 1 < d[cur-1]){
                    d[cur-1] = d[cur] + 1;
                    q.push(cur-1);
                    visited[cur-1] =true;
                }
            }
        }
        if (cur < n){
            if (!visited[cur+1]){
                if (d[cur] + 1 < d[cur+1]){
                    d[cur+1] = d[cur] + 1;
                    q.push(cur+1);
                    visited[cur+1] =true;
                }
            }
        }
    }
}

int main(){
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m;
    cin >> n >> m;

    F0(i,m){
        int j;
        cin >> j;
        BFS(j);
    }

    cout << *max_element(begin(d), begin(d)+n) << endl;

    return 0;
}
