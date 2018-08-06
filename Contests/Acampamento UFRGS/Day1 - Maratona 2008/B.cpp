#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
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
// #define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};

int n;
unordered_map<string, int> qt;
// unordered_map<ii, int> dist;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n){
		if(!n) break;
		qt.clear();
		string a, b;
		cin >> a >> b;
		int atual = 1;
		qt[a] = atual++;
		qt[b] = atual++;
		
		vector<pair< int, ii > > vec[5001];
		int dist[5001][30];
		for(int i=0;i<5001;i++) for(int j=0;j<=29;j++) dist[i][j] = 99999999;

		for(int i=0;i<n;i++){
			string aa, bb, cc;
			cin >> aa >> bb >> cc;

			if(qt[aa] == 0) qt[aa] = atual++;
			if(qt[bb] == 0) qt[bb] = atual++;

			vec[qt[aa]].pb({qt[bb],{cc[0]-97, sz(cc)}});
			vec[qt[bb]].pb({qt[aa],{cc[0]-97, sz(cc)}});
		}

		//-97
		priority_queue<pair<int, ii> , vector< pair<int, ii>  >, greater<pair<int, ii> > > pq;
		pq.push({qt[a], {27, 0}});
		for(int i='a'-97;i<='z'-97 + 3;i++) dist[qt[a]][i] = 0;

		while(sz(pq)){
			pair<int, ii> u = pq.top();
			pq.pop();
			for(auto i : vec[u.F]){
				if(i.S.F == u.S.F) continue;
				if(dist[u.F][u.S.F] + i.S.S < dist[i.F][i.S.F]){
					dist[i.F][i.S.F] =  dist[u.F][u.S.F] + i.S.S;
					pq.push({i.F, {i.S.F, dist[i.F][i.S.F]}});
				}
			}
		}

		int anss = 99999999;
		for(int i='a'-97;i<='z'-97;i++){
			anss = min(anss, dist[qt[b]][i]);
		} 

		if(anss == 99999999) cout << "impossivel" << endl;
		else cout << anss << endl;


	}


	return 0;
}