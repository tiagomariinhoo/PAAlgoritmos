#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 50000 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())

map<int, lli> s, d;
lli vec[2002][2002];
int n;

/*
  QUESTÃO IMPORTANTE, PROPRIEDADES DE MATRIZ

  Problema: Pegar a soma das diagonais de um bispo

  Pegando a soma das diagonais [cima direita baixo]
  e [cima esquerda baixo]

  Para pegar a diagonal de cima esquerda baixo
    - Basta pegarmos as coordenadas fazendo i+j (pois
      todos os índices nessa diagonal somam o mesmo numero)
  Para pegar a diagonal de cima direita baixo
    - Basta checarmos i-j (pois todos os índices nessa
      diagonal subtraem e dão o mesmo número)

  Para checar se estão na mesma diagonal, basta checar se
  a soma dos dois índices é par ou ímpar.

*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin >> vec[i][j];
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      s[i+j] += vec[i][j];
      d[i-j] += vec[i][j];
    }
  }

  vector<pair<lli, pair<int ,int > > > aux;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      aux.push_back({s[i+j] + d[i-j],{i, j}});
    }
  }

  sort(aux.begin(), aux.end());

  lli ans = 0, ans2 = 0;
  int _x, _y, _xx, _yy;
  for(int i=0;i<sz(aux);i++){
    int x = aux[i].S.F, y = aux[i].S.S;
    lli sum2 = aux[i].F - vec[x][y];

    if((x+y)%2==0){
      if(sum2 >= ans){
        ans = sum2, _x = x, _y = y;
      }
    } else {
      if(sum2 >= ans2){
        ans2 = sum2, _xx = x, _yy = y;
      }
    }

  }
  cout << ans2 + ans << endl;

  cout << _x << " " << _y << " " << _xx << " " << _yy << endl;


  return 0;
}