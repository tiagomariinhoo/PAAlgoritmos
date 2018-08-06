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
typedef vector<lli> vi;
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

int n,m,x,y;
char vec[1001][1001];
int pd[2][1001];
int aa[1001], bb[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x >> y;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> vec[i][j];

	for(int i=0;i<m;i++){
		int a = 0, b = 0;
		for(int j=0;j<n;j++) a += (vec[j][i] == '.'), b += (vec[j][i] == '#');
		aa[i+1] = a, bb[i+1] = b;
	}

	memset(pd, 191919191, sizeof pd);
	pd[0][0] = pd[1][0] = 0;

	// for(int i=0;i<=m;i++) cout << aa[i] << " - " << bb[i] << endl;

	for(int i=0;i<=m;i++){
		int a = 0, b = 0;
		for(int j=1;j<=y and i+j<=m;j++){
			a += aa[i+j], b += bb[i+j];
			if(j >= x){
				pd[0][i+j] = min(pd[0][i+j], pd[1][i] + a);
				pd[1][i+j] = min(pd[1][i+j], pd[0][i] + b);
			}
		}
	}	

	// for(int i=0;i<=m;i++){
		// cout << pd[0][i] << " - " << pd[1][i] << endl;
	// }

	cout << min(pd[0][m], pd[1][m]) << endl;

	return 0;
}