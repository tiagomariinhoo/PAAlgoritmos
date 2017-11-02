#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF 1000000
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
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

/*
	Finding Minimum-Cost Path in a 2-D MAtrix
	DP
*/

int cost[101][101];

int minCost(int m, int n){
	int i,j;
	int tc[101][101];
	tc[0][0] = cost[0][0];

	for(int i=1;i<=n;i++) tc[i][0] = tc[i-1][0] + cost[i][0];
	for(int j=1;j<=m;j++) tc[0][j] = tc[0][j-1] + cost[0][j];

	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++) tc[i][j] = min(tc[i-1][j-1], min(tc[i-1][j], tc[i][j-1])) + cost[i][j];
	
	return tc[m][n];
}


int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) s(cost[i][j]);

	cout << minCost(2, 2) << endl;

	return 0;
}