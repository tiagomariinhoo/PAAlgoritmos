#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 100500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
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
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

/*
	COMBINATORICS
	FAST EXP
	MODULAR MATH

*/

string s;
lli k;

lli fe(lli x, lli y){
	lli ans = 1;
	while(y > 0){
		if(y&1) ans = (ans * x) % MOD;
		y /= 2;
		x = (x*x)%MOD;
	}
	return ans;
}

int main(){
	cin >> s;
	cin >> k;

	lli a = 0;
	for(int i=0;i<sz(s);i++){
		if(s[i] == '0' or s[i] == '5') a = (a + fe(2,i))%MOD;
	}

	lli b = fe(2,sz(s))-1;
	lli c = fe(b, MOD-2);
	lli d = (fe(2, k*sz(s))-1)%MOD;
	cout << a << " - "<< b << " - " << c << " - " << d << endl;
	// cout << (((a * c)%MOD) * d)%MOD << endl;
	// cout << ans << endl;

	cout << ((d/b) * a)%MOD << endl;

	return 0;
}