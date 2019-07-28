#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define M_PI 3.1415
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n;
vector<int> vec[MAXN];
int pd[MAXN][4];


void read(){
  cin >> n;
  for(int i=2;i<=n;i++){
    int a;
    cin >> a;
    vec[a].push_back(i);
  }
}

//F = melhor possível do node atual pra baixo
//G = melhor sem usar esse vértice
//H = sendo a segunda cabeça

//G = soma dos F's dos filhos
//H = 2 G's + Outros F's

/*
  Se o node atual pode ser cabeça, ou seja:
  - Tem 3 filhos e um dos filhos tem pelo menos dois filhos
  Se não pode: 
  F = Max(g, h);
 */

bool comp(pair<int, pair<int, int > > a, pair<int, pair<int, int > > b){
  return (a.S.S - a.S.F) < (b.S.S - b.S.F);
}

int solve(int x, int nivel){

  int &ans = pd[x][nivel];

  if(ans != -1) return ans;

  int sum = 0;

  if(nivel == 0){
    for(auto i : vec[x]){
      sum += max(solve(i, 0), solve(i, 1) + 1);
    }
  } else {
    if(sz(vec[x]) < 2) return ans = -1e8;

    vector<pair<int, pair<int, int> > > aux;
    for(auto i : vec[x]){
      aux.push_back({i, {solve(i, 0), solve(i, 1) + 1}});
    }
    
    sort(aux.begin(), aux.end(), comp);

    sum += (aux[0].S.F + aux[1].S.F);
    for(int i=2;i<sz(aux);i++) sum += max(aux[i].S.S, aux[i].S.F);

    if(nivel == 1){
      int ansi = -1;
      for(int i=2;i<sz(aux);i++){
        ansi = max({
          ansi, solve(aux[i].F, 2) - max(aux[i].S.F, aux[i].S.S)
        });
      }
        sum += ansi;
    }

  }

  return ans = sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  read();
  memset(pd, -1, sizeof pd);

  cout << solve(1, 0) << endl;

  return 0;
}