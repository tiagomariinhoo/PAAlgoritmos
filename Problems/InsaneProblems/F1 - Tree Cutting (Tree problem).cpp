#include <bits/stdc++.h>
using namespace std;

#define MAXN 300010
#define MAXL 20
#define F first
#define S second
#define lli long long int

int n;
int c[MAXN];
vector<int> vec[MAXN];
int vis[MAXN];
pair<int, int> dp[MAXN];
int pai[MAXN];
int ans = 0;

pair<int, int> dfs(int x){
	vis[x] = 1;

	pair<int, int> aux;
	if(c[x] == 1) aux.F = 1;
	else if(c[x] == 2) aux.S = 1;

	for(auto i : vec[x]){
		if(vis[i]) continue;
		pai[i] = x;
		// aux += dfs(i);
		pair<int, int> aux2 = dfs(i);
		aux.F += aux2.F;
		aux.S += aux2.S;
	}
	dp[x] = aux;
	return dp[x];
}

void dfs2(int x){
	vis[x] = 1;

	for(auto i : vec[x]){
		if(vis[i]) continue;

		if((dp[1].F - dp[i].F == 0 and dp[i].S == 0)
			or (dp[1].S - dp[i].S == 0 and dp[i].F == 0)){
			ans++;
		}

		dfs2(i);
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++) cin >> c[i];

  for(int i=0;i<n-1;i++){
  	int a, b;
  	cin >> a >> b;
  	vec[a].push_back(b);
  	vec[b].push_back(a);
  }

  dfs(1);
  memset(vis, 0, sizeof vis);
  dfs2(1);

  cout << ans << endl;

  return 0;
}