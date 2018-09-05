#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
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
typedef vector<lli> vi;
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
#define MAXN 400001

int n, q;
int tree[MAXN][10];
int lazy[MAXN];
int cnt[10], aux[10];

void build(int node = 1, int start = 1, int end = n){
	if(start == end) tree[node][1] = 1;
	else {
		int mid = (start + end) >> 1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node][1] = tree[2*node+1][1] + tree[2*node][1];
	}
}

void upd(int node, int v){
	int atual = lazy[node];

}

void updateRange(int l, int r, int val, int node = 1, int start = 1, int end = n){
	
	if(lazy[node] != 0){ 
		int v = lazy[node];
		for(int i=0;i<9;i++) cnt[i] = tree[node][i];
		for(int i=0;i<9;i++) tree[node][(i+v)%9] = cnt[i];

			// tree[node] += (end - start + 1) * lazy[node];
			if(start != end){
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}

	if(start > end or start > r or end < l) return ;

	if(start >= l and end <= r){
		// tree[node] += (end - start + 1) * val;
		for(int i=0;i<9;i++) cnt[i] = tree[node][i];
		for(int i=0;i<9;i++) tree[node][(i+val)%9] = cnt[i];

		if(start != end){
			lazy[2*node] += val;
			lazy[2*node+1] += val;
		}
		return ;
	}
	
	int mid = (start + end) >> 1;
	updateRange(l, r, val, 2*node, start, mid);
	updateRange(l, r, val, 2*node+1, mid+1, end);

	for(int i=0;i<9;i++) tree[node][i] = tree[2*node][i] + tree[2*node+1][i];
}

void query(int l, int r, int node = 1, int start = 1, int end = n){

	if(lazy[node]){
		int v = lazy[node];
		for(int i=0;i<9;i++) aux[i] = tree[node][i];
		for(int i=0;i<9;i++) tree[node][(i+v)%9] = aux[i]; 
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start > r or end < l) return ;
	if(start >= l and end <= r){
		for(int i=0;i<9;i++) cnt[i] += tree[node][i];
		return ;
	}

	int mid = (start + end) >> 1;
	query(l, r, 2*node, start, mid);
	query(l, r, 2*node+1, mid+1, end);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  build();

  for(int i=0;i<q;i++){
  	int a, b;
  	cin >> a >> b;
  	a++, b++;
  	memset(cnt, 0, sizeof cnt);
  	query(a, b);
  	int atual = 0, jj = 0;

  	for(int j=0;j<9;j++){
  		if(cnt[j] >= atual) atual = cnt[j], jj = j;
  	}
  	
  	updateRange(a, b, jj);
  }

  for(int i=1;i<=n;i++){
  	memset(cnt, 0, sizeof cnt);
  	query(i,i);
  	for(int i=0;i<9;i++){
  		if(cnt[i]){
  			cout << i << endl;
  			break;
  		}
  	}
  }

  return 0;
}