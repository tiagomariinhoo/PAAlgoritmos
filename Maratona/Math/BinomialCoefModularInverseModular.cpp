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
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int a, b, n;

/*	
	Coeficiente Binomial,
	só serve para N até 20.
	Para calcularmos nCr mod p, onde p e primo
	Sendo nCr:
	n! / (r! * (n - r)!)
	Nós calculamos o fatorial mod P e usamos
	modular inverse pra achar nCr mod p. Se nós
	temos que achar nCr mod M (onde m é não primo)
	pode-se fatorizar M em primos e usar teorema chines
	do resto
	e achar nCr mod m

	Isso acontece porque calcular:
	n! / (r! ( n - r)! ) % p dá overflow mt facil
	Pela propriedade
	n/k = n* k^-1
	Usando o pequeno teorema de fermat:
	a^p = a (mod p) para P primo e a > 0, p > a
	então a ^ (p-2) = a ^ -1 (mod p), portanto, conseguimos
	achar a^(p-2)%p , facilmente com fast Expo

*/

lli C(lli n, lli r){
	lli f[n+1];
	f[0] = 1;

	for(int i=1;i<=n;i++){
		f[i] = i*f[i-1];
	}
	return f[n]/f[r]/f[n-r];
}

lli powMod(lli a, lli b, lli MOD2){
	lli x=1, y = a;
	while(b > 0){
		if(b%2==1){
			x = (x*y);
			if(x > MOD2) x%=MOD2;
		}
		y = (y*y);
		if(y > MOD2) y%=MOD2;
		b/=2;
	}
	return x;
}

/*
	Modular Multiplicative INverse
	Using Euler's Theorem
	a^(phi(m)) = 1 (mod m)
	a ^ (-1) = a^(m-2) (mod m)

*/

lli inverseEuler(lli n, lli MOD2){
	return powMod(n, MOD2-2, MOD2);
}

/*
	Coeficiente Binomial com Modulo
*/

bool check(int aa, int bb){
	lli res = (a*aa) + (b*bb);

	while(res > 0){
		int atual = res%10;
		res /= 10;
		if(atual != a and atual != b) return false; 
	}
	return true;
}

lli C(lli n, lli r, lli MOD2){
	vector<lli> f(n+1, 1);
	// Dá pra otimizar o calculo do fatorial
	// Deixando todos pre calculados
	for(lli i = 2;i<=n;i++){
		f[i] = (f[i-1]*i)%MOD2;
	}
	return (f[n]*((inverseEuler(f[r], MOD2) * inverseEuler(f[n-r], MOD2))%MOD2))%MOD2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> n;
	int aa = n, bb = 0;
	lli ans = 0;
	while(aa >= 0){
		if(check(aa, bb)){
			ans += C(n, min(aa, bb), MOD);
			if(ans > MOD) ans%= MOD;
		}
		aa--;
		bb++;
	}

	cout << ans%MOD << endl;

	return 0;
}