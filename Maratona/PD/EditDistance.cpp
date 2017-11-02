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
	Edit Distance
*/

int dist(string s1, string s2, int m, int n){
	int dp[101][101];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]));
		}
	}
	return dp[m][n];
}

int main(){
	string a = "sunday";
	string b = "saturday";
	cout << dist(a,b,a.size(), b.size()) << endl;
}