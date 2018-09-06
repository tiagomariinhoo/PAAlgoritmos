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
#define MAXN 200001

int n, cc;
int vec[MAXN], vec2[MAXN];
lli pd[MAXN][2];

lli knap(int obj, int can){
	if(obj == n) return 0;
	if(pd[obj][can] != - 1) return pd[obj][can];

	lli a = 0, b = 0, c = 0;
	if(can){
		a = knap(obj+1, 1) + vec2[obj];
		b = knap(obj+1, 1) + vec2[obj] - cc;
		c = knap(obj+1, 0);
	} else {
		a = knap(obj+1, 1) + vec2[obj] - cc;
		b = knap(obj+1, 0);
	}

	return pd[obj][can] = max(a, max(b, max(c, 0LL)));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> cc;
  for(int i=0;i<n;i++) cin >> vec[i];
  memset(pd, -1, sizeof pd);
	for(int i=0;i<n-1;i++){
		vec2[i] = vec[i+1] - vec[i];
	}

	// for(int i=0;i<n;i++) cout << vec2[i] << " ";
	// 	cout << endl;

	cout << knap(0, 0) << endl;


  return 0;
}