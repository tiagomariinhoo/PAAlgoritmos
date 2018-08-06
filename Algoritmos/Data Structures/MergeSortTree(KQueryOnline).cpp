#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
// #define lli unsigned long long int
#define lb long double
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

/*
	Given an array of N elements and you have to answer Q queries (L,R,K), to count
	the numbers smaller than K in range L to R. Xor KQUERY Online
*/

int n,m;

vi tree[1000000];
int a[250000];

void build(int node=1, int l=1, int r=n){
	// cout << node << endl;
	if(l == r){
		tree[node].pb(a[l]);
		return ;
	}
	int mid = (r + l) / 2;
	build(2*node, l, mid);
	build(2*node+1, mid+1, r);
	
	tree[node].resize(sz(tree[2*node]) + sz(tree[2*node+1]));
	// cout << sz(tree[2*node+1]) << " - " << sz(tree[2*node+2]) << endl;
	merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), tree[node].begin());
	// cout << "Tree size : " << sz(tree[node]) << endl;
	// for(int i=0;i<sz(tree[node]);i++){
	// 	cout << tree[node][i] << " ";
	// } cout << endl;

}

//l start r end
int query(int l, int r, int k, int node = 1, int start = 1, int end = n){
	// cout << l << " - " << r << " - " << k << endl;
	if(end < l or start > r) return 0;
	if(l <= start and end <= r){
		return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
	}
	int mid = (start + end) / 2;
	return query(l, r, k, 2*node, start, mid) + query(l, r, k, 2*node+1, mid+1, end);
}

int main(){
	ios_base::sync_with_stdio(false);
	
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		build();
		cin >> m;
		int last = 0;
		for(int i=0;i<m;i++){
			int aa,b,c;
				cin >> aa >> b >> c;
				// cout << aa << " - "<< b << " - " << c << endl;
				// if(aa > b){
				// 	// cout << aa << " - " << b << endl;
				// 	last = 0;
				// 	cout << last << endl;
				// 	continue;
				// }
				// if(aa < 1) aa = 1;
				// if(b > n) b = n;
				aa^=last;
				b^=last;
				c^=last;
				last = abs(query(aa,b,c));
				cout << last << endl;
				// if(pd[{aa,{b,c}}] > 0) cout << pd[{aa,{b,c}}] << endl;
				// else{
					// pd[{aa,{b,c}}] = abs(query(aa,b,c));
				// cout <<pd[{aa,{b,c}}] << endl;
				// }
			// last = pd[{aa,{b,c}}];
		}



	return 0;
}