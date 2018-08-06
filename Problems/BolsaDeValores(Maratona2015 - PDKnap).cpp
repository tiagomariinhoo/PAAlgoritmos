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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,k;
vi vec;
int pd[200005][3];
int ans = 0;

int knap(int obj, int atual, int at){
	if(obj == sz(vec)) return 0;
	if(pd[obj][at] != -1) return pd[obj][at];

	int a = -1;
	if(at){
		a = knap(obj+1, atual, at) + vec[obj] - (vec[obj-1]);
	}
	int b = knap(obj+1, obj, 0);
	int c = knap(obj+1, obj, 1) - k;

	return pd[obj][at] = max(a, max(b, c));
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	memset(pd, -1, sizeof pd);


	cout << knap(0 , 0, 0) << endl;

	return 0;
}
