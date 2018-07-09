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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
// int ddx[] = {1, 0};
// int ddy[] = {1, 1};
#define d 256

int n, tot;
vector<string> ss;
vector<ii> vec;
vector<pair<string, int> > aux2;
map<string, int> vis, mapa;
vector< vector<ii> > aux3;
map<vi, int> vis2;
vi ans;
int atual = 1;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		if(!mapa[s]) mapa[s] = atual++;
		vec.pb({mapa[s], sz(s)});
		ss.pb(s);
		tot += sz(s);
	}
	tot += sz(ss) - 1;

	for(int i=0;i<sz(vec);i++){
		vector<ii> aux2;
		vi aa;
		for(int j=i;j<sz(vec);j++){
			aux2.pb({vec[j].F, vec[j].S});
			aa.pb(vec[j].F);
			if(vis2[aa]) continue;
			vis2[aa] = 1;
			aux3.pb(aux2);
		}
	}

	int ans = tot;

	for(int i=0;i<sz(aux3);i++){
		vector<ii> aa = aux3[i];
		int tamAtual = 0;
		for(int j=0;j<sz(aa);j++) tamAtual += aa[j].S;
			tamAtual += sz(aa) - 1;

		int oco = 0;
		for(int j=0;j<sz(vec);j++){
			if(vec[j].F == aa[0].F){
				int aaa = 0;
				for(int k=0;k<sz(aa) and k + j < sz(vec) ;k++){
					if(aa[k].F != vec[j+k].F) break;
					aaa++;
				}
				if(aaa == sz(aa)) oco++, j = j + sz(aa) - 1;
			}
		}

		if(oco >= 2){
			ans = min(ans, tot - (tamAtual - sz(aa))*oco);
		}

	}

	cout << ans << endl;

	return 0;
}