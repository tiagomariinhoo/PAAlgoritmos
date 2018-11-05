#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20
#define MOD2 998244353

/*
Deduz a fórmula com o somatório
10^tamanho*i
E vira o somatório de uma pg
*/

lli modFexp(lli x, lli y, lli p){
	lli ans = 1;
	while(y > 0){
		if(y&1) ans = (ans*x)%p;
		y = y >> 1;
		x = (x*x)%p;
	}
	return ans;
}

lli extgcd(lli a, lli b, lli &x, lli &y){
    lli g = a; x = 1; y = 0;
    if(b!=0) g = extgcd(b,a%b,y,x), y -= (a/b)*x;
    return g;
}

long long int mulMod(long long int x,long long  int y,long long int n){
    return ((x % n)*(y % n)) % n;
}

long long int invMod(long long int a, long long int m){
    lli x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else return 0; //Nao Resolvivel
}


long long int divMod(long long int x,long long int y,long long int n){
    return mulMod(x,invMod(y,n),n);
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
  	lli m, n;
  	cin >> m >> n;
  	lli tam = (floor(log10(n)) + 1);
  	// cout << "Tam : " << tam << endl;
  	lli ans = (n * divMod(modFexp(10, m*tam, MOD) - 1, modFexp(10, tam, MOD) - 1, MOD))%MOD;
  	// cout << n * (modFexp(10, m*tam, MOD) - 1)%MOD/(modFexp(10, tam, MOD) - 1)%MOD << endl;
  	cout << ans << endl;

  }


    return 0;
}