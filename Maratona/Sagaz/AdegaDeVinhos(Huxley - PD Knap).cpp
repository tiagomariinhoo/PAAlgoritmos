#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
int vec[301];
int pd[301][301];

int knap(int a, int b, int ano){
	if(a > b) return 0; 
	
	if(pd[a][b] != -1) return pd[a][b];

	int aa = knap(a + 1, b, ano + 1) + (vec[a] * ano);
	int bb = knap(a, b - 1, ano + 1) + (vec[b] * ano);

	return pd[a][b] = max(aa, bb);
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(pd, -1, sizeof pd);
	cin >> n;
	for(int i=0;i<n;i++) cin >> vec[i];


	knap(0, n-1, 1);
	int ans = 0;
	
	cout << pd[0][n-1] << endl;
	
	return 0;
}