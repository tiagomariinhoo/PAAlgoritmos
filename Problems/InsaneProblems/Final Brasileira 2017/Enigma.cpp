#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

string s;
int k;
int n;

string ans;
int pd[1001][1000][9];

/*
	Engima (Final Brasileira 2017)
	dado uma string de até 1000 digitos, fazer um número que seja divisivel por k

	Primeiro:
		Notar que todo número 110 por exemplo, é feito por:
			10^2 * 1 + 10^1 * 1 + 10^0 * 0
		Com isso, dá pra usar aritmetica modular pra pegar resto de números grandes
	Usa digit dp e tenta formar o número gulosamente, a primeira resposta é a certa

*/

lli modFexp(lli x, lli y, lli p){ //Calcula x^y%p em Log Y
	int ans2 = 1;
	while(y > 0){
		if(y&1) ans2 = (ans2*x) % p;
		y = y >> 1;
		x = (x*x) % p;
	}
	return ans2;
}


int solve(int pos, int resto, int can){
	if(pos == sz(s)){
		if(!resto){
			cout << ans << endl;
			exit(0);
		}
		return !resto;
	}
	int &anss = pd[pos][resto][can];
	if(anss != -1) return anss;

	lli xx = modFexp(10LL, n - pos - 1, k);

	int a = 0;
	if(s[pos] == '?'){
		int atual = !can ? 1 : 0;
		for(int i=atual;i<=9;i++){
			ans[pos] = (i + '0');
			a += solve(pos+1,  (resto + (xx * i)%k)%k, i >= 1 ? 1 : can);
		}
	} else {
		a += solve(pos+1, (resto + (xx * (s[pos] - '0'))%k)%k, s[pos] - '0' >= 1 ? 1 : can);
	}
	return anss = a;
}


int main(){ 
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> k;
  n = sz(s);
  ans = s;
  memset(pd, -1, sizeof pd);
  solve(0,0,0);

  // lli resto = 0;
  // for(int i=0;i<sz(s);i++){
  // 	lli xx =modFexp(10LL, n - i - 1, k);
  // 	if(n - i - 1 >= 1) resto += (xx  *)
  // }

  cout << "*" << endl;

    return 0; 
} 