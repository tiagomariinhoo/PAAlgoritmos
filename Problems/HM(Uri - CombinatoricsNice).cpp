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

//https://www.urionlinejudge.com.br/judge/pt/challenges/view/358/6
/*
	Combinatorics problem
	Todas as subsequencias
	2^n-1
*/

string s;
vi vec;

lli fexp(lli x, lli y){ //Calcula x^y em Log Y
	lli ans = 1;
	while(y>0){
		if(y&1) ans = (ans*x)%MOD;
		y = y >> 1;
		x = (x*x)%MOD;
	}
	return ans%MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	int a = 0;
	for(int i=0;i<sz(s);i++){
		if(s[i] == 'F') a++;
		else a--;
		if(!a) vec.pb(0);
	}
	lli aa = sz(vec);
	cout << fexp(2,aa-1) << endl;


	return 0;
}