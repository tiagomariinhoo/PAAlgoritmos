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
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
#define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};

int dx[] = {1, 0};
int dy[] = {0, 1};

int n,m;
int vec[100001];
set<int> vec2;
vi ans[100001];

lli gcd(lli a, lli b){
	while(1){
		if(a == 0) return b;
		b%=a;
		if(b == 0) return a;
		a %= b;
	}
}

int phi(int a){
	int res = a;
	for(int p=2;p*p<=a;p++){
		if(a%p == 0){
			while(a%p == 0) a/=p;
			res -= res/p;
		}
	}
	if(a > 1) res -= res/a;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i=1;i<=n;i++) vec[i] = phi(i);

	if(m < n-1){
		cout << "Impossible" << endl;
		return 0;
	}

	for(int i=1;i<=n-1;i++){
		ans[i].pb(i+1);
		m--;
	}

	if(m){
		for(int i=1;i<=min(n, 600);i++){
			if(!m) break;
			for(int j=i+2;j<=min(n, 600);j++){
				if(!m) break;
				if(gcd(i, j) == 1){
					m--;
					ans[i].pb(j);
				}
			}
		}
	}

	if(m){
		cout << "Impossible" << endl;
	} else {
		cout << "Possible" << endl;
		for(int i=1;i<=n;i++){
			for(int j=0;j<sz(ans[i]);j++){
				cout << i << " " << ans[i][j] << endl;
			}
		}
	}

	return 0;
}