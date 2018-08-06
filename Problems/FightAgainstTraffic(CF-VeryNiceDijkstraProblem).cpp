#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF 191919
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
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

int n,m,s,t;
vector<ii> vec[1010];
int disa[1010];
int disb[1010];
set<ii> pos;

/*
	Dijkstra no inicial para todos
	Dijkstra no final para todos
	Compara os vertices que ainda não estão ligados
*/

void dijk(int x, int y){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	disa[x] = 0;
	pq.push({0,x});
	
	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();
		for(auto i : vec[u]){
			if(disa[i.S] > i.F + disa[u]){
				disa[i.S] = i.F + disa[u];
				pq.push({disa[i.S], i.S});
			}
		}
	}

	disb[y] = 0;
	pq.push({0,y});

	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();
		for(auto i : vec[u]){
			if(disb[i.S] > i.F + disb[u]){
				disb[i.S] = i.F + disb[u];
				pq.push({disb[i.S], i.S});
			}
		}
	}
}

int main(){
	cin >> n >> m >> s >> t;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		vec[a].pb({1,b});
		vec[b].pb({1,a});
		if(a > b) swap(a,b);
		pos.insert({a,b});
	}

	for(int i=1;i<=n;i++) disa[i] = 101919, disb[i] = 191919;

	dijk(s,t);

	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(pos.find({i,j}) == pos.end()){
				pos.insert({i,j});
				if(disa[i] + disb[j] + 1 >= disa[t] and disa[j] + disb[i] + 1 >= disa[t]) ans++;
			}
		}
	}

	cout << ans << endl;

	return 0;
}