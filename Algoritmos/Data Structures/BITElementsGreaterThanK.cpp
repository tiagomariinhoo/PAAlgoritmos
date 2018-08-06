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

struct query{
	int i;
	int j;
	int k;
	int pos;
};

bool comp(ii &a, ii &b){ return a.F > b.F; }
bool comp2(query &a, query &b){ return a.k > b.k; }

int tree[30010];
int ans[200010];
int n,m;
vector<ii> vec;
vector<query> q;

void atualiza(int x, int v){
	for(;x<=n;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
	int s = 0;
	for(;x>0;x-=(x&-x)) s += tree[x];
	return s;
}

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		int a;
			cin >> a;
			vec.pb({a,i});
	}

	sort(vec.begin(), vec.end(), comp);

	cin >> m;

	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		q.pb({a,b,c,i+1});
	}

	sort(q.begin(), q.end(), comp2);

	int j = 0;
	for(int i=0;i<sz(q);i++){
		int ii = q[i].i;
		int jj = q[i].j;
		int kk = q[i].k;
		int pos = q[i].pos;
		while(vec[j].F > kk and j < n) atualiza(vec[j].S,1), j++;

		ans[pos] = sum(jj) - sum(ii - 1);
	}

	for(int i=1;i<=m;i++) printf("%d\n", ans[i]);
		
	return 0;
}