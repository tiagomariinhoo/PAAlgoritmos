#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353 
#define lli unsigned long long int
#define sz(a) int(a.size())
#define M_PI 3.1415
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, f;
int can[MAXN];
vector<int> marcado;
int grau[MAXN];
int sum[MAXN];
int nivel[MAXN];
vector<pair<int, int> > vec[MAXN];
pair<int, int> pai[MAXN];
int sub = 0, tot;

/*
A solução consiste em somar todos as arestas certas
E subtrair do maior caminho
 */

void solve(int u, int &friends, int soma){
  int v, ff = 0, cost;
  friends = can[u];
  if(can[u]) sub = max(sub, soma);
  for(auto i : vec[u]){
    int v = i.S;
    solve(v, ff, soma + i.F);
    if(ff > 0){
      tot += i.F;
      friends += ff;
    }
  }
  // cout << "Node and Friends" << endl;
  // cout << u << " - " << friends << endl;
  // cout << tot << " - " << sub << " - " << soma << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> n >> f){
    for(int i=1;i<=n;i++) vec[i].clear(), can[i] = 0, grau[i] = 0, pai[i] = {i, 0}, sum[i] = 0, nivel[i] = 0;
    marcado.clear();
    tot = 0, sub = 0;
    for(int i=0;i<n-1;i++){
      int a, b, c;
      cin >> a >> b >> c;
      vec[a].push_back({c, b});
      // vec[b].push_back({c, a});
      // pai[b] = {a, c};
      // grau[a]++;
    }

    for(int i=1;i<=f;i++){
      int a;
      cin >> a;
      // marcado.push_back(a);
      can[a] = 1;
    }

    solve(1, n, 0);

    cout << tot - sub << endl;
  }

  return 0;
}