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
// int aa[1001], bb[1001];
int aa[2][1001];
int pd[2][1001][1001];

int solve(int pos, int atual, int cum){
	if(pos == m and cum < x or cum > y) return 1e9;
	if(pos == m) return 0;

	int &ans = pd[atual][pos][cum];
	if(ans != -1) return ans;

	int atual2 = atual ? 0 : 1;
	int aaa = 1e9;
	if(cum < x){
		aaa = min(aaa, solve(pos + 1, atual, cum + 1) + aa[atual][pos]);
	} else if(cum >= x and cum < y){
		aaa = min(aaa, solve(pos + 1, atual, cum + 1) + aa[atual][pos]);
		aaa = min(aaa, solve(pos + 1, atual2, 1) + aa[atual2][pos]);
	} else if(cum == y){
		aaa = min(aaa, solve(pos + 1, atual2, 1) + aa[atual2][pos]);
	}
	return ans = aaa;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> x >> y;

	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> vec[i][j];

	for(int i=0;i<m;i++){
		int a = 0, b = 0;
		for(int j=0;j<n;j++){
			if(vec[j][i] == '.') a++;
			else b++;
		}
		aa[0][i] = a, aa[1][i] = b;
	}

	memset(pd, -1, sizeof pd);

	cout << min( solve(0,0,0), solve(0,1,0) ) << endl;

	return 0;
}