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

int n, k;
vector<int> vec[MAXN];
int c[MAXN];
lli pd[MAXN][4];

/*
  Abordagem diferente
  DP in tree
*/

lli solve(int x, int pai, int cor, int corPai){

  if(cor == corPai or (c[x] != 0 and cor != c[x])) return 0;

  lli &ans = pd[x][cor];
  if(ans != -1) return ans;
  ans = 1;
  for(auto i : vec[x]){
    if(i == pai) continue;
    lli aux = 0;
    for(int j=1;j<=3;j++){
      aux += (solve(i, x, j, cor))%MOD;    
    }
    ans = (ans * aux)%MOD;
  }

  return ans%MOD;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    freopen("barnpainting.in", "r", stdin);
  freopen("barnpainting.out", "w", stdout);

  cin >> n >> k;
  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  for(int i=0;i<k;i++){
    int a, b;
    cin >> a >> b;
    c[a] = b;
  }

  lli ans = 0;
  memset(pd, -1, sizeof pd);

  for(int i=1;i<=3;i++){
    ans += solve(1,0,i,0)%MOD;
  }

  cout << ans%MOD << endl;

  return 0;
}