#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
// typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 5010
#define MAXL 20
#define MOD2 998244353

int n, k, x;

lli dp[MAXN][MAXN];
lli vec[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k >> x;
  for(int i=1;i<=n;i++) cin >> vec[i];
 
  for(int i=0;i<=n;i++) for(int j=0;j<=x;j++){
    dp[i][j] = -LLONG_MAX;
  }

  dp[0][0] = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=x;j++){
      for(int p=1;p<=k;p++){
        if(i - p < 0) break;
        dp[i][j] = max(dp[i][j], dp[i-p][j-1] + vec[i]);
      }
    }
  }


  lli ans = -LLONG_MAX;
  for(int i=(n-k+1);i<=n;i++) ans = max(ans, dp[i][x]);

  if(ans <= 0) cout << -1 << endl;
else cout << ans << endl;

  return 0;
}  
