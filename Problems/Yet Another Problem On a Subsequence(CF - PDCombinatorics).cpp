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
#define MOD2 998244353

int n;
vi vec(1001);
lli pd[1001][1001];

lli knap(int obj, int qt){
	if(obj == n){
		if(qt == 0) return 1;
		return 0;
	}
	if(pd[obj][qt] != -1) return pd[obj][qt];

	lli &ans = pd[obj][qt];
	ans = knap(obj+1, qt);
	if(ans > MOD2) ans %= MOD2;
	if(qt == 0){
		if(vec[obj] > 0 and vec[obj] < n){
		 ans = (ans + knap(obj+1,vec[obj])%MOD2)%MOD2;
		}
	} else {
		ans = (ans + knap(obj+1, qt-1)%MOD2)%MOD2;
	}
	return ans%MOD2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++) cin >> vec[i];
		memset(pd, -1, sizeof pd);

	cout << (knap(0, 0) - 1)%MOD2 << endl;

	return 0;
}