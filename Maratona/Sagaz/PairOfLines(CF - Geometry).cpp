#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 100005
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
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

/* Dado 1 até 100k de pontos,
	Verificar se duas retas cobrem todos os pontos dados
	Sol : Parte de 5 pontos, fazendo dois conjuntos e se consegue
	fazer o resto dos dois conjuntos
*/

bool ans = false;
vector<ii> vec;

bool col(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3){
	return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
}

void test(ii a, ii b, ii c, ii d, ii e){
	// cout << a.F << " - " << a.S << " - " << b.F << " - " << b.S << " - " << c.F << " - " << c.S << " - " << d.F << " - " << d.S << " - " << e.F << " - " << e.S << endl;
	vector<ii> aa, bb;
	aa.pb(a), aa.pb(b);

	if(col(aa[0].F,aa[0].S ,aa[1].F,aa[1].S , c.F, c.S)) aa.pb(c);
	else bb.pb(c);

	if(col(aa[0].F ,aa[0].S ,aa[1].F ,aa[1].S ,d.F, d.S)) aa.pb(d);
	else bb.pb(d);

	if(col(aa[0].F ,aa[0].S ,aa[1].F , aa[1].S, e.F, e.S)) aa.pb(e);
	else {
		if(sz(bb) >= 2){
			if(col(bb[0].F, bb[0].S, bb[1].F, bb[1].S, e.F, e.S)) bb.pb(e);
			else return ;
		} else bb.pb(e);
	}

	for(int i=5;i<sz(vec);i++){
		if(col(aa[0].F, aa[0].S, aa[1].F, aa[1].S, vec[i].F, vec[i].S)) aa.pb(vec[i]);
		else {
			if(sz(bb) < 2) bb.pb(vec[i]);
			else {
				if(col(bb[0].F, bb[0].S, bb[1].F, bb[1].S, vec[i].F, vec[i].S)) bb.pb(vec[i]);
				else {
					return ;
				}
			}
		}
	}

	// for(int i=0;i<sz(aa);i++) cout << aa[i].F << " _ " << aa[i].S << endl;
	// cout << " -- " << endl;
	// for(int i=0;i<sz(bb);i++) cout << bb[i].F << " _ " << bb[i].S << endl;
	// 	cout << endl;
	ans = true;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		vec.pb({a,b});
	}

	sort(vec.begin(), vec.end());

	if(sz(vec) <= 4){
		cout << "YES" << endl;
		return 0;
	} else {
		do{
			test(vec[0], vec[1], vec[2], vec[3], vec[4]);
		} while(next_permutation(vec.begin(), vec.begin() + 5));
	}

	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}