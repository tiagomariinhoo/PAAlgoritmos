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

map<lli, lli> pd;

lli solve(lli n){
	if(n <= 1) return n;
	if(pd[n] != 0) return pd[n];
	lli a = n/2, b = n/3, c = n/4;
	lli aa = solve(a), bb = solve(b), cc = solve(c);
	return pd[n] =  max(a + b + c, max(aa + bb + cc, n));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n){
	
		cout << solve(n) << endl;
	}

	return 0;
}