#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 999999999999
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

int n,q;
vector<lli> vec;
vector<lli> pd;
lli cum;

lli ans(lli a){
	lli x;
	if(a + cum >= pd[sz(pd)-1]){
		cum = 0;
		return n;
	}
	x = lower_bound(pd.begin(), pd.end(), a + cum) - pd.begin();
	// cout << x << " - " << a << " - " << cum << endl;
	if(pd[x] > a + cum){
		// cum += pd[x] - (a + cum)
		cum += a;
		return n - x;
	}
	cum += a;
	return n - (x + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	pd.pb(vec[0]);
	for(int i=1;i<sz(vec);i++) pd.pb(pd[i-1] + vec[i]);

	// for(int i=0;i<n;i++) cout << pd[i] << " ";
	// 	cout << endl;

	for(int i=0;i<q;i++){
		lli a;
		cin >> a;
		cout << ans(a) << endl;
	}



	return 0;
}