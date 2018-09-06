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
#define MAXN 500001

string s;
int vec[2001];
ii pd[2001][2001];

int solve2(int l, int r){
	if(l > r or l == sz(s) or r < 0) return 0;
	if(l == r) return pd[l][r].F = 1;
	if(pd[l][r].F != -1) return pd[l][r].F;

	int a = solve2(l+1, r);
	int b = solve2(l, r-1);
	int c = solve2(l+1, r-1) + (s[l] == s[r])*2;

	return pd[l][r].F = max(a, max(b, c));
}

ii solve(int l, int r){
	if(l > r or l == sz(s) or r < 0) return {0,0};
	if(l == r) return pd[l][r] = {vec[l], 1};
	if(pd[l][r].F != -1) return pd[l][r];

	ii a = solve(l+1, r);
	ii b = solve(l, r-1);
	ii c = solve(l+1, r-1);
	if(s[l] == s[r]){
		c.S += (s[l] == s[r])*2;
		c.F += (vec[l] + vec[r]);
	}

	vector<ii> aux2;
	aux2.pb(a), aux2.pb(b), aux2.pb(c);
	sort(aux2.begin(), aux2.end());
	return pd[l][r] = aux2[2];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 	cin >> s;
 	int n;
 	cin >> n;
 	int ans = 0;

 	for(int i=0;i<sz(s);i++) for(int j=0;j<sz(s);j++) pd[i][j].F = -1, pd[i][j].S = -1;

 	if(!n){
 		cout << solve2(0, sz(s) - 1) << endl;
 		return 0;
 	}


 	for(int i=0;i<n;i++){
 		int a;
 		cin >> a;
 		vec[a-1] = 1;
 	}

 	ii aux = solve(0, sz(s)-1);
 	cout << aux.S << endl;

  return 0;
}