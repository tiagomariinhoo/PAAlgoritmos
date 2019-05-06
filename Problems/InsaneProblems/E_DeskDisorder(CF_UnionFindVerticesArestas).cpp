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

int n;
set<int> vec[MAXN];
int mark[MAXN];
int tam = 0, tam2 = 0;
int pai[MAXN];
int peso[MAXN];
int vert[MAXN];
set<int> aux[MAXN];

/*
  Primeiro separamos em componentes conectados
  O Union Find guarda o número de vértices e o número de arestas
  do conjunto inteiro

  3 Casos para cada conjunto:
  Se E == V
    Só temos duas possibilidades de organizar
  Se V == E + 1
    Temos uma árvore, á "V" jeitos de organizar
  Se existe Self-loop em alguém do conjunto
    Temos apenas um jeito de organizar.

*/

int proc(int x){
  if(pai[x] == x) return x;
  return pai[x] = proc(pai[x]);
}

void junta(int a, int b){
  a = proc(a);
  b = proc(b);

  if(a != b){
    pai[b] = a;
    peso[a] += peso[b] + 1;
    peso[b] = 0;
    vert[a] += vert[b];
    vert[b] = 0;
    if(mark[b]) mark[a] = 1;
  } else 
    peso[a]++;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=1;i<=2*n;i++) pai[i] = i, vert[i] = 1, aux[i].insert(i);


  for(int i=0;i<n;i++){
    int a, b;
    cin >> a >> b;
    if(a == b){
      a = proc(a);
      mark[a] = 1;
    }

    junta(a, b);
  }

  lli ans = 1;
  for(int i=1;i<=2*n;i++){
    if(peso[i] and vert[i]){
      if(mark[i]) continue;
      if(vert[i] == peso[i] + 1) ans = (ans * vert[i])%MOD;
      else if(vert[i] == peso[i]) ans = (ans*2)%MOD;
    }
  }

  cout << ans << endl;

  return 0;
}