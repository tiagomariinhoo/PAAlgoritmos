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
typedef pair<lli,lli> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};


int n;
int tree[1000002];
int maxi;
int zero;
void atualiza(int x, int v){
	for(;x<=1000000;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
	int s = 0;
	for(;x>0;x-=(x&-x)) s += tree[x];
	return s;
}
int main(){	
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	// cout << 100000 << endl;
	// for(int i=0;i<100000;i++) cout << 1000000 << endl;

	// cin >> n;
	s(n);
	for(int i=0;i<n;i++){
		int a;
		// cin >> a;
		s(a);
		// cout << maxi << " -- " << a-1 << endl;
		// cout << sum(maxi) - (sum(a-1)) << endl;
		int ans = 0;
		if(a > 0) ans = n - (sum(1000000) - sum(a-1));
		else ans = n - (sum(1000000)) - zero;

		printf("%d\n", ans);
		if(a > 0)
		atualiza(a, 1);
		else zero++;
	}

	return 0;
}
