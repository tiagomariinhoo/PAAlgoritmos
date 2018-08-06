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
#define MOD 1e9 + 9
#define MOD2 1e9 + 7
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
// #define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};

int tree[100001];
int n;
map<int, int> last;
int ans[300001];
vector< pair<int, ii> > qq;
int a[100001];

void atualiza(int x, int v){
	for(;x<=n;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
	int s = 0;
	for(;x>0;x-=(x&-x)) s += tree[x];
	return s;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int aa, bb;
		cin >> aa >> bb;
		qq.pb({bb, {aa, i}});
	}

	sort(qq.begin(), qq.end());

	int j = 0;
	for(int i=1;i<=n;i++){
		if(last[a[i]] == 0) last[a[i]] = i, atualiza(i, 1);
		else{
			atualiza(last[a[i]], -1);
			last[a[i]] = i;
			atualiza(i, 1);
		}
		
		while(i == qq[j].F){
			ans[qq[j].S.S] = sum(qq[j].F) - sum(qq[j].S.F - 1);
			j++;
		}
	}

	for(int i=0;i<q;i++){
		cout << ans[i] << endl;
	}

	return 0;
}