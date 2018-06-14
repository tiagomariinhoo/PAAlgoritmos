#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX INT_MAX
#define MAXL LLONG_MAX
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
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
vector<ii> cond;
vi vec[66000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		cond.pb({a,b});
	}

	queue<int> q;
	for(int i=0;i<sz(cond);i++) if(cond[i].F == 1) q.push(i);

	while(!q.empty()){
		
		int u = q.front();
		q.pop();

		if(cond[u].F == 0) continue;

		int sum = 0;
		for(int i=0;i<sz(vec[u]);i++) sum ^= vec[u][i];

		int a = sum ^ cond[u].S;
		vec[a].pb(u);
		vec[u].pb(a);
		cond[u].F--;
		cond[a].F--;

		if(cond[a].F == 1) q.push(a);
	}

	set<ii> ans;

	for(int i=0;i<=n-1;i++){
		for(int j=0;j<sz(vec[i]);j++){
			int u = vec[i][j];
			int v = i;
			if(u == v) continue;
			if(v > u) ans.insert({u,v});
			else ans.insert({v,u});
		}
	}

	cout << sz(ans) << endl;
	for(auto i : ans) cout << i.F << " " << i.S << endl;

	return 0;
}