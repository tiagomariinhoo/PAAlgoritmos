#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e5 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int

int tree[MAXN + 1];
int ans[MAXN + 1];
int at[MAXN + 1];
int vis[MAXN + 1];
int q;
int global = MAXN + 1;
vector<pair<int, pair<int, int> > > vec;

void crivo(){
  at[1] = 1;
  for(int i=2;i<=MAXN;i++){
    if(!at[i]) for(int j=2;i*j<=MAXN;j++) at[i*j] = 1;
  }
}

void atualiza(int x, int v){
  for(;x<=MAXN;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
  int s = 0;
  for(;x>0;x-=(x&-x)) s += tree[x];
  return s;
}

bool comp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
  if(a.S.F == b.S.F) return a.F < b.F;
  return a.S.F > b.S.F;
}

void solve2(int atual){
  for(int i = global ; i > atual ; i--){
    if(!at[i]){
      for(int j = 1; j*i <= MAXN ; j++){
        if(!vis[i*j]) atualiza(i*j, -1), vis[i*j] = 1;
      }
    }
  }
  global = atual;
}

void solve(){
  for(int i = 0; i < vec.size(); i++){
    int k = vec[i].S.F;
    int n = vec[i].F;
    int idx = vec[i].S.S;

    solve2(k);
    ans[idx] = sum(n);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> q;
  for(int i=0;i<q;i++){
    int n, k;
    cin >> n >> k;
    vec.push_back({n,{k, i}});
  }

  sort(vec.begin(), vec.end(), comp);
  for(int i=2;i<=MAXN;i++) atualiza(i, 1);

  crivo();
  solve();

  for(int i=0;i<q;i++) cout << ans[i] << endl;

  return 0;
}