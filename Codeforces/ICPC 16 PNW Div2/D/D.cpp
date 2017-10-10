#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

// Fenwick Tree with ranged queries and point updates . Complexity : O ( log ( n ) )
template < typename T > struct FenwickTree {
	int N ; vector <T > A ;
	FenwickTree ( int n ) : N ( n +1) , A ( N ) {}
	// Create tree with n elements
	T rq ( int b ) { int r =0; for (; b ;b -= b & - b ) r += A [ b ]; return r ; }
	// Get sum A [0 , b )
	T rq ( int a , int b ) { return rq ( b ) - rq ( a ) ; }
	// Get sum A [a , b )
	void adjust ( int i , T v ) { for ( i ++; i < N ; i += i & - i ) A [ i ]+= v ; }
		// A [ i ] += v
	int lower_bound ( T sum ) {
		// find min i such that sum ( A [0.. i ]) >= sum
		int i = 0;
		// Returns n if there is no such i
		for ( int b = 1 << (31 - __builtin_clz ( N ) ) ; b ; b /= 2)
		// ( Only works if A [ i ] >= 0
		if ( i + b < N && sum > A [ i + b ]) sum -= A [ i + b ] , i += b ;
		// for all i )
		return i ;
	}
};

int main() {

	int N, K, R; cin >> N >> K >> R;

	FenwickTree<ll> F(N);
	vi hasCamera(N,0);
	for (int i=0;i<K;i++) {
		int cam; cin >> cam; cam--;
		hasCamera[cam] = 1;
		F.adjust(cam, 1);
	}

	int ans = 0;
	for (int i=R-1;i<N;i++) {
		int l;
		l = i-R;
		ll cameras = F.rq(l+1, i+1);

		// if not enough cameras, need to put, let us greedily put to the right
		if (cameras < 2) {
			// start at cur pos
			int j = i;
			while (cameras < 2) {
				// if free, put here
				if (!hasCamera[j]) {
					hasCamera[j] = 1;
					F.adjust(j, 1);
					cameras++;
					ans++;
				}
				j--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
