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

int n,m;
int larg;
vi vec;
vector<ii> aux;

lli solve(){
	int a = 0, b = sz(vec)-1;
	lli ans = 0;
	int qt = 0;
	if(n%larg==0) qt = n/larg;
	else return LLONG_MAX;
	// if(larg * qt != n) return LLONG_MAX;
	// cout << "Qt : " << qt << endl;
	// cout << sz(aux) << endl;
	if(sz(aux) < qt) return LLONG_MAX;
	for(int i=0;i<qt;i++) ans += aux[i].S;
	return ans;
}

void build(){
	int a = 0, b = sz(vec) - 1;

	while(a <= b){
		if(vec[b] == m){
			aux.pb({vec[b], 1});
			b--;
		} else if(vec[a] == m){
			aux.pb({vec[a], 1});
			a++;
		} else if(vec[b] + vec[a] == m and a != b){
			aux.pb({m, 2});
			a++, b--;
		} else if(vec[a] + vec[b] > m){
			b--;
		} else if(vec[a] + vec[b] < m) a++;
		else a++, b--;
	}
	// for(int i=0;i<sz(aux);i++) cout << aux[i].S << " ";
	// cout << endl;

	sort(aux.begin(), aux.end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> m){
		if(!n and !m) break;
		cin >> larg;
		n*=100, m*=100;
		// larg /= 100;
		int k;
		cin >> k;
		vec.clear(), aux.clear();
		map<int, int> qt, qt2;
		for(int i=0;i<k;i++){
			int a;
			cin >> a;
			a*=100;
			vec.pb(a);
		}
		// if(n%larg!=0 and m%larg!=0){
		// 	cout << "impossivel" << endl;
		// 	continue;
		// }
		sort(vec.begin(), vec.end());

		lli ans = LLONG_MAX;
		build();
		ans = min(ans, solve());
		swap(n, m);
		aux.clear();
		build();
		ans = min(ans, solve());

		if(ans == LLONG_MAX){
			cout << "impossivel" << endl;
		} else cout << ans << endl;
	}
	

	return 0;
}