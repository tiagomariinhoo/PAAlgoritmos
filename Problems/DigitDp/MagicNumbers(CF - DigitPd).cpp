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

int m, d;
string a, b;
string vec;
lli pd[2001][2][2001];

lli solve(int pos, int can, int rem){
	if(pos == sz(vec)) return (rem == 0);

	lli &ans = pd[pos][can][rem];
	if(ans != -1) return ans;

	lli aux = 0;
	int atual = can ? vec[pos] - '0' : 9;

	if((pos+1)%2==0){
		if(atual < d) return ans = 0;
		aux += solve(pos+1, atual == d ? can : 0 , (rem*10 + d)%m)%MOD;
	} else {
		for(int i = (pos == 0 ? 1 : 0); i<=atual; i++){
			if(i == d) continue;
			if(i == atual) aux += solve(pos+1, can, (rem*10 + i)%m)%MOD;
			else aux += solve(pos+1, 0, (rem*10 + i)%m)%MOD;
		}
	}

	return ans = aux;
}

int test(){	
	lli sum = 0;
	for(int i=0;i<sz(a);i++){
		if((i+1)%2==0){
			if(a[i] - '0' != d) return 0;
		} else {
			if(a[i] - '0' == d) return 0;
		}
		sum = (sum * 10 + a[i]- '0')%m; 
	}

	if(!sum) return 1;

	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> d;
	cin >> a;
	cin >> b;

	vec = a;
	memset(pd, -1, sizeof pd);
	lli aa = solve(0, 1, 0);
	vec = b;
	memset(pd, -1, sizeof pd);
	lli bb = solve(0, 1, 0);
	
	cout << (bb - (aa) + test())%MOD << endl;

	return 0;
}