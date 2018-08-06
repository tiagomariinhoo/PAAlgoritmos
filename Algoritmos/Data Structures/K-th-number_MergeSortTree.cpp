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
//ios_base::sync_with_stdio(false);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m, A[101010];
vi tree[4*101010];
vi vec;

void build(int node = 1, int start = 1, int end = n){
	if(start == end){
		tree[node].pb(A[start]);
		return ;
	}

	int mid = (start + end) >> 1;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node].resize(sz(tree[2*node]) + sz(tree[2*node+1]));
	merge(tree[2*node].begin(), tree[2*node].end(), tree[2*node+1].begin(), tree[2*node+1].end(), tree[node].begin());
}

int query(int l, int r, int k, int node = 1, int start = 1, int end = n){
	if(start > r or end < l) return 0;
	if(start >= l and end <= r) return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();

	int mid = (start + end) >> 1;
	int p1 = query(l, r, k, 2*node, start, mid);
	int p2 = query(l, r, k, 2*node+1, mid+1, end);
	return (p1 + p2);
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> A[i], vec.pb(A[i]);
	
	sort(vec.begin(), vec.end());

	for(int i=1;i<=n;i++){
		int resp = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin() + 1;
		// cout << "Resp : " << resp << endl;
		A[i] = resp;
	}
	// for(int i=1;i<=n;i++) cout << A[i] << " ";
	// 	cout << endl;

	build();


	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		int l = 1, r = n, mid, ans;
		while(l <= r){
			mid = (l + r) >> 1;
			int k = query(a,b,mid);
			if(k >= c){
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		cout << vec[ans-1] << endl;
	}


	return 0;
}