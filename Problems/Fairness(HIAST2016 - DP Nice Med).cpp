#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (5151)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
#define endl '\n'
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
// barr \

int t;
vi vec;
int pd[101][20501];


int solve(int pos, int cur){
	if(pos == sz(vec)) return abs(cur);

	int &ans = pd[pos][cur];
	if(ans != -1) return ans;

	int aa = solve(pos+1, cur + vec[pos]);
	int bb = solve(pos+1, cur - vec[pos]); 
	aa = abs(aa), bb = abs(bb);
	return ans = max({abs(cur), min({aa, bb})});
}

int main(){

	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vec.clear();
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			vec.pb(a);
		}
		memset(pd, -1, sizeof pd);
		cout << solve(0, 0) << endl;
	}

	return 0;
}