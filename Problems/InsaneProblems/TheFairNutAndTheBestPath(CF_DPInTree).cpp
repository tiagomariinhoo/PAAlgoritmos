#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

lli n;
lli c[MAXN];
vector<pair<lli,lli> > vec[MAXN];
lli dp[MAXN][2];
int nivel[MAXN];
int papi[MAXN];

void dfs(lli x, lli pai){
  for(auto i : vec[x]){
    if(i.S == pai) continue;
    nivel[i.S] = nivel[x] + 1;
    dfs(i.S, x);
  }
}

void dfs2(lli x, lli pai){
  for(auto i : vec[x]){
    if(i.S == pai) continue;
    dfs2(i.S, x);
  }

  for(auto i : vec[x]){
    if(nivel[i.S] > nivel[x]) continue;
    dp[i.S][1] = max({dp[i.S][1], dp[x][1] + c[i.S] - i.F});
    if(dp[x][1] + c[i.S] - i.F >= dp[i.S][1]){
      dp[i.S][1] = dp[x][1] + c[i.S] - i.F;
      papi[i.S] = x;
    }
  }
}

void dfs3(lli x, lli pai){
  for(auto i : vec[x]){
    if(i.S == pai) continue;
    if(papi[x] != i.S){
      dp[i.S][0] = max({dp[i.S][0], dp[x][1] + c[i.S] - i.F});
    }
      dp[i.S][0] = max({dp[i.S][0], dp[x][0] + c[i.S] - i.F});
    dfs3(i.S, x);    
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++) cin >> c[i], dp[i][0] = c[i], dp[i][1] = c[i];

  for(int i=0;i<n-1;i++){
    lli a, b, c;
    cin >> a >> b >> c;
    vec[a].push_back({c, b});
    vec[b].push_back({c, a});
  }

  lli ans = 0;
  dfs(1, 0);
  dfs2(1, 0);
  dfs3(1, 0);
  // for(int i=1;i<=n;i++){
  //   cout << i << " - " << dp[i][0] << " - " << dp[i][1] << endl;
  //   cout << i << " --- " << papi[i] << endl;
  // }
  for(int i=1;i<=n;i++) ans = max({ans, dp[i][1], dp[i][0]});




  cout << ans << endl;

  return 0;
}