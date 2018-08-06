#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 999999999999
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

int n,d;
int pd[30001][500];
int vis[30001][500];
int qt[30001];
vi vec;
int maxi;

/*
	A pd é [n][d], o d vai até 30 mil, dando mle
	Como a diferença máxima de passos que ele pode dar é 251, podemos
	usar a pd[30001][301] para não dar mle	
	Mas lembrando de pegar atual - (d - 250);

*/

// int knap(int obj, int atual){
// 	if(obj > maxi or (atual - (d-250)) >= 301) return 0;
// 	if(obj == maxi) return pd[obj][atual - (d - 250)] = qt[obj];
// 	if(pd[obj][atual - (d-250)] != -1) return pd[obj][atual - (d - 250)];
// 	if(atual <= 1){
// 		int aa = knap(obj + 1 + atual, atual + 1) + qt[obj];
// 		int bb = knap(obj + atual, atual) + qt[obj];
// 		return pd[obj][atual - (d - 250)] = max(aa, bb);
// 	}
// 	int aa = knap(obj + 1 + atual, atual + 1) + qt[obj];
// 	int bb = knap(obj + atual, atual) + qt[obj];
// 	int cc = knap(obj - 1 + atual, atual - 1) + qt[obj];

// 	return pd[obj][atual - (d - 250)] = max(aa, max(bb, cc));
// }

int knap(int obj, int atual){
	int k = atual - (d-250);
	if(obj >= 30001) return 0;
	if(vis[obj][k]) return pd[obj][k];
	vis[obj][k] = 1;
	int ans;
	if(atual == 1){
		ans = qt[obj] + max(knap(obj + atual + 1, atual + 1), knap(obj + atual, atual));
	} else {
		ans = qt[obj] + max(knap(obj + atual + 1, atual + 1), max(knap(obj + atual, atual), knap(obj + atual - 1, atual - 1)));
	}
	return pd[obj][k] = ans;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> d;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		qt[a]++;
		maxi = max(maxi, a);
		vec.pb(a);
	}

	cout << knap(d, d) << endl;


	return 0;
}