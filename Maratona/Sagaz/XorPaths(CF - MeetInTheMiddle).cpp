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
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};

int dx[] = {1, 0};
int dy[] = {0, 1};

map<pair<int, int> , map<long long int, int> > qt;
lli vec[21][21];
lli n, m, k;

map< pair<int, int> , int> dig;
long long int ans = 0;

void bfs(int x, int y, long long int atual){
	if(dig[{x,y}]){
		qt[{x,y}][atual]++;
		return ;
	}

	for(int i=0;i<2;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 and xx < n and yy >= 0 and yy < m){
			bfs(xx, yy, atual ^ vec[xx][yy]);
		}
	}
}

void bfs2(int x, int y, long long int atual2){
	if(dig[{x, y}]){
		long long int atual = atual2 ^ k;
		ans += qt[{x,y}][atual];
		return ;
	}

	for(int i=0;i<2;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 and xx < n and yy >= 0 and yy < m){
			long long int aux = atual2 ^ vec[xx][yy];
			if(dig[{xx, yy}]) aux = atual2;
			bfs2(xx, yy, aux);
		}
	}
}


int main(){

	cin >> n >> m >> k;
	// n = 7, m = 5;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> vec[i][j];

	int x = 0, y = (m+n)/2 - 1;
	while(y >= 0) dig[{x++, y--}] = 1;
	bfs(0, 0, vec[0][0]);
	dx[0] = -1, dx[1] = 0;
	dy[0] = 0, dy[1] = -1;
	bfs2(n-1, m-1, vec[n-1][m-1]);

	if(n == 1 and m == 1){
		if(vec[0][0] == k){
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return 0;
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		if(dig[{i, j}]) cout << " * ";
	// 		else cout << " a ";
	// 	} cout << endl;
	// }

	cout << ans << endl;

	return 0;
}