#include <bits/stdc++.h>
using namespace std;

int N;
long long MOD_VALUE = pow(10, 9)+ 7;

bool isPeaceful(vector<int> &owner, vector<vector<int>> &GRAPH) {
    for (int i=0;i<N;i++) {
        bool hasSameOwnerAsNeighbour = false;
        for (int j=0;j<(int)GRAPH[i].size();j++) {
            if (owner[i] == owner[j]) {
                hasSameOwnerAsNeighbour = true;
                break;
            }
        }
        if (!hasSameOwnerAsNeighbour) return false;
    }
    return true;
}

long long getAns(int curCity, vector<int> &owner, vector<vector<int>> &GRAPH, map<pair<int, vector<int>>, long long> &memo) {
    // either sib 0 owns curCity or not
    if (curCity == N) {
        if (isPeaceful(owner, GRAPH)) return 1;
        else return 0;
    }

    owner[curCity] = 0;
    long long ansIfOwned = getAns(curCity+1, owner, GRAPH, memo);
    owner[curCity] = 1;
    long long ansIfNotOwned = getAns(curCity+1, owner, GRAPH, memo);

    memo[make_pair(curCity, owner)] = (ansIfOwned + ansIfNotOwned)%MOD_VALUE;
    return (ansIfOwned + ansIfNotOwned)%MOD_VALUE;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> N;
    vector<vector<int>> GRAPH(N);
    for (int i=0;i<N-1;i++) {
        int u,v;
        cin >> u >> v;
        u--;v--;
        GRAPH[u].push_back(v);
        GRAPH[v].push_back(u);
    }

    // 0 means sibling 0, 1 sibling 1
    vector<int> owner(N,0);

    map<pair<int, vector<int>>, long long> memo;

    long long ans = getAns(0, owner, GRAPH, memo);

    cout << ans << endl;
    return 0;
}
