#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
int pai[100001];
int peso[100001];
ii vec[100001];
vi q;

int proc(int x){
	if(pai[x] == x) return x;
	return pai[x] = proc(pai[x]);
}

void join(int a, int b){
	int aa = proc(a);
	int bb = proc(b);

	if(aa == bb) return ;

	if(peso[aa] < peso[bb]){
		pai[aa] = bb;
	} else if(peso[bb] < peso[aa]){
		pai[bb] = aa;
	} else {
		pai[aa] = bb;
		peso[bb]++;
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		vec[i+1] = {a, b};
	}

	for(int i=0;i<m;i++){
		int a; 
		cin >> a;
		q.pb(a);
	}

	for(int i=1;i<=n;i++) pai[i] = i;

	int ans = n;
	vi anss;
	for(int i=sz(q)-1;i>=0;i--){
		int a = vec[q[i]].F, b = vec[q[i]].S;
		anss.pb(ans);
		int aa = proc(a), bb = proc(b);
		// cout << a << " - " << b << " : " << aa << " - " << bb << endl;
		// cout << "Ans : " << ans << endl;
		if(aa != bb) ans--, join(a, b);
		// ans = max(1, ans);
	}

	for(int i=sz(anss)-1;i>=0;i--) cout << anss[i] << endl;

	return 0;
}