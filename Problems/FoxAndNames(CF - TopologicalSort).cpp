#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
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
vector<string> vec;
vector<char> ans;
int vis[200];
vector<char> adj[200];
int grau[200];

void comp(string a, string b){
	int aa = 0;
	while(a[aa] == b[aa] and aa < min(sz(a), sz(b))) aa++;
	if(aa == sz(a) or aa == sz(b)){
		if(sz(a) > sz(b)){
			cout << "Impossible" << endl;
			exit(0);
		}
		return ;
	}
	adj[a[aa]].pb(b[aa]);
	grau[b[aa]]++;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		vec.pb(s);
	}

	for(int i=0;i<sz(vec)-1;i++){
		comp(vec[i], vec[i+1]);
	}
	queue<char> q;
	for(int i='a';i<='z';i++) if(!grau[i]) q.push(i);
	
	while(!q.empty()){
		char u = q.front();
		ans.pb(u);
		q.pop();
		for(int i=0;i<sz(adj[u]);i++){
			char v = adj[u][i];
			grau[v]--;
			if(!grau[v]) q.push(v);
		}
	}

	// for(int i=0;i<sz(ans);i++) cout << ans[i] << " ";
	// 	cout << endl;

	if(sz(ans) == 26){
		for(int i=0;i<sz(ans);i++) cout << ans[i];
			cout << endl;
	} else {
		cout << "Impossible" << endl;
	}


	return 0;
}