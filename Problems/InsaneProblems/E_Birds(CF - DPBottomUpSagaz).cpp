#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n,w,b,x;
lli disp[MAXN];
lli custo[MAXN];
lli dp[(int) 1e3 + 10][(int) 1e4 + 10];

//https://codeforces.com/contest/922/problem/E

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> w >> b >> x;
  for(int i=1;i<=n;i++) cin >> disp[i];
  for(int i=1;i<=n;i++) cin >> custo[i];

  for(int i=0;i<=(int)1e3+9;i++){
    for(int j=0;j<=(int)1e4+9;j++){
      dp[i][j] = -1;
    }
  }

  dp[1][0] = w;
  // for(int i=1;i<=disp[1];i++) dp[1][i] = w;
  // for(int i=1;i<=disp[1];i++) dp[1][i] = w - (custo[1])*i;
  lli ans = 0;
  for(lli i=1;i<=n;i++){
      for(lli j=0;j<=(int)1e4+1;j++){
      if(dp[i][j] == -1) break;
      for(int k=0;k<=min(disp[i], (lli)(1e4 + 1));k++){
        if((dp[i][j]) - (k*custo[i]) < 0) break;
        if(dp[i+1][j+k] == -1) dp[i+1][j+k] = 0;
        dp[i+1][j+k] = max(max(dp[i+1][j+k], 0LL), 
          min(dp[i][j] - (custo[i]*k) + (x), w + (k+j)*b)
        );
      }
    }
  }

  // for(int i=1;i<=n+1;i++){
    // for(int j=0;j<=19;j++){
      // cout << dp[i][j] << " ";
    // } cout << endl;
  // }

  for(lli i=0;i<=n+1;i++){
    for(lli j=0;j<=(int)1e4+1;j++) if(dp[i][j] != -1) ans = max(ans, j);
  }

  cout << ans << endl;

  return 0;
}