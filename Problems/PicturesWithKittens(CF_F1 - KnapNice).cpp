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
#define MAXN 100010
#define MAXL 20
#define MOD2 998244353

int n, x, k;
vector<lli> vec;
lli pd[210][210][210];

lli solve(int pos, int kk, int xx){
  if(pos == sz(vec)){
    if(xx or kk <= 0) return -LLONG_MAX;
    return 0;
  }
  if(kk <= 0) return -LLONG_MAX;
  // lli ans = &pd[pos][kk][xx];
  if(pd[pos][kk][xx] != -1) return pd[pos][kk][xx];

  lli a = -LLONG_MAX, b = -LLONG_MAX;
  if(xx){
      a = solve(pos + 1, k, xx - 1) + vec[pos];
      b = solve(pos + 1, kk-1, xx);
  } else {  
    a = solve(pos + 1, kk-1, xx);
  }

  return pd[pos][kk][xx] = max(a, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k >> x;
  for(int i=0;i<n;i++){
    lli a;
    cin >> a;
    vec.pb(a);
  }

  // if((double)n/x > (double)k){
    // cout << -1 << endl;
    // return 0;
  // }
  memset(pd, -1LL, sizeof pd);
  lli ans = solve(0, k, x);
  if(ans < 0) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
} 