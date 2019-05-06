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

vector<int> vec[MAXN];
int c[MAXN];
int n, k;
int vis[MAXN];
lli pd[MAXN][4];
int ans = 0;
vector<int> op[MAXN];

/*
  DP IN TREE
  Dado um grafo, 3 opções de cores
  Número de jeitos para pintar o grafo
  Sendo que o grafo pode ter alguns vértices pintados antes

  Desce até as folhas e volta calculando para cada filho
*/

void dfs(int x, int pai){
  for(auto i : vec[x]){
    if(i == pai) continue;
    dfs(i, x);
  }

  for(int i=1;i<=3;i++){
    if(c[x] != 0 and c[x] != i) continue;
    pd[x][i] = 1;
    for(auto j : vec[x]){
      if(j == pai) continue;
      int atual, atual2;
      atual = (i+1), atual2 = (i+2);
      if(atual > 3) atual -= 3;
      if(atual2 > 3) atual2 -= 3;
      pd[x][i] *= (pd[j][atual] + pd[j][atual2])%MOD;
      pd[x][i] %= MOD;
    }
  }
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
    op[a].push_back(b);
  }

  dfs(1, 0);
  lli ans = 0;
  for(int i=1;i<=3;i++) ans = (ans + pd[1][i])%MOD;
  cout << ans << endl;

  return 0;
}