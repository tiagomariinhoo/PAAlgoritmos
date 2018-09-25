#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define MOD2 998244353
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001

int n,k;
lli pd[1001][2002][2][2];

lli solve(int pos, int comp, int a, int b){
  if(pos == n){
    return comp == k;
  }

  lli &ans = pd[pos][comp][a][b];
  if(ans != -1) return ans%MOD2;

  lli aa = 0;
  if(pos == 0){
    aa += (solve(pos+1, comp+1, 1, 1)%MOD2 + solve(pos+1, comp+1, 2, 2)%MOD2)%MOD2;
    aa += (solve(pos+1, comp+2, 1, 2)%MOD2 + solve(pos+1, comp+2, 2, 1)%MOD2)%MOD2;
  } else{
    if(a == 1 and b == 1){
      aa += solve(pos+1, comp, 1, 1)%MOD2;
      aa += solve(pos+1, comp+1, 1, 2)%MOD2;
      aa += solve(pos+1, comp+1, 2, 1)%MOD2;
      aa += solve(pos+1, comp+1, 2, 2)%MOD2;
    } else if(a == 1 and b == 2){
      aa += solve(pos+1, comp, 1, 1)%MOD2;
      aa += solve(pos+1, comp, 1, 2)%MOD2;
      aa += solve(pos+1, comp+2, 2, 1)%MOD2;
      aa += solve(pos+1, comp, 2, 2)%MOD2;
    } else if(a == 2 and b == 1){
      aa += solve(pos+1, comp, 1, 1)%MOD2;
      aa += solve(pos+1, comp+2, 1, 2)%MOD2;
      aa += solve(pos+1, comp, 2, 1)%MOD2;
      aa += solve(pos+1, comp, 2, 2)%MOD2;
    } else {
      aa += solve(pos+1, comp+1, 1, 1)%MOD2;
      aa += solve(pos+1, comp+1, 1, 2)%MOD2;
      aa += solve(pos+1, comp+1, 2, 1)%MOD2;
      aa += solve(pos+1, comp, 2, 2)%MOD2;
    }
  }

  return pd[pos][comp][a][b] = aa%MOD2;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  memset(pd, -1, sizeof pd);

  cout << solve(0, 0, 0, 0)%MOD2 << endl;
  
   return 0; 
} 