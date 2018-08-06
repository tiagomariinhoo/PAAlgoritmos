#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 0x3f3f
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

/*
	Longest sum subsequence array
	Querys
*/

struct Node{
	lli maxSum;
	lli preSum;
	lli sufSum;
	lli totalSum;
	Node(){
		preSum = sufSum = maxSum = totalSum = -INT_MAX;
	}
};

int n,m;
lli a[51000];
Node tree[150000];

//Merge left and right child
Node merge(Node a, Node b){
	Node aux;	

	aux.totalSum = a.totalSum + b.totalSum;
	aux.maxSum = max({a.maxSum, a.sufSum + b.preSum, b.maxSum});
	aux.preSum = max(a.preSum, a.totalSum + b.preSum);
	aux.sufSum = max(a.sufSum + b.totalSum, b.sufSum);

	return aux;
}

void build(int node = 1, int start = 1 ,int end = n){
	if(start == end){
		tree[node].preSum = a[start];
		tree[node].sufSum = a[start];
		tree[node].totalSum = a[start];
		tree[node].maxSum = a[start];
	}	else {
		int mid = (start + end) >> 1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = merge(tree[2*node], tree[2*node+1]);
	}
}

Node query(int l, int r, int node = 1, int start = 1, int end = n){
	if(start > r or end < l){
		Node aux;
		return aux;
	}
	if(start >= l and end <= r) return tree[node]; 

	int mid = (start + end) >> 1;
	Node p1 = query(l, r, 2*node, start, mid);
	Node p2 = query(l ,r, 2*node+1, mid+1, end);
	Node ans = merge(p1, p2);
	return ans;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	cin >> m;
	
	build();

	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		Node aux = query(a, b);
		cout << aux.maxSum << endl;
	}

	return 0;
}