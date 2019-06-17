#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(1e6 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
typedef pair<int,int> ii;

int n;
vector<pair<int, int> > vec;
vector<pair<int, pair<int, int> > > lines;
int tot = 0;
map<long double, int> qt;
set<pair<int, ii> > cre, decc, hori, vert, line;
map<pair<int, ii>, long double > slopeLine;

/*
  Questão de Geometria
  Dado N Pontos, pegar todas as retas que tem intersecção
  Tomando cuidado com as coincidentes e as paralelas

  Forma n² retas, joga as retas em um set, pra verificar
  se a reta coincide com alguma outra, basta dividir tudo pelo gcd.

  Vê as retas que tem o mesmo coeficiente angular, pois são paralelas
*/

pair<int, pair<int, int> > formLine(ii a, ii b){
  if(a.F > b.F) swap(a, b);
  int dy = b.S - a.S;
  int dx = a.F - b.F;
  return {dy, {dx, dy*a.F + dx*a.S}};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a, b;
    cin >> a >> b;
    vec.push_back({a, b});
  }

  lli ans = 0;
  for(int i=0;i<sz(vec);i++){
    for(int j=i+1;j<sz(vec);j++){
      pair<int, int> a = vec[i], b = vec[j];
      if(a.F > b.F) swap(a, b);
      pair<int, pair<int, int > > auxLine = formLine(a, b);
      int d = (__gcd(auxLine.F, __gcd(auxLine.S.F, auxLine.S.S)));
      auxLine.F /= d, auxLine.S.F /= d, auxLine.S.S /= d;

      if(auxLine.F < 0) auxLine.F*=-1, auxLine.S.F*=-1, auxLine.S.S*=-1;

      if(b.F == a.F){
        hori.insert({auxLine.F,{auxLine.S.F, auxLine.S.S}});
      } else if(a.S == b.S){
        vert.insert({auxLine.F,{auxLine.S.F, auxLine.S.S}});
      } else {
        long double slope = (long double)(b.S - a.S)/(b.F - a.F);
        slopeLine[{auxLine.F,{auxLine.S.F, auxLine.S.S}}] = slope;
        line.insert({auxLine.F,{auxLine.S.F, auxLine.S.S}});
      }

    }
  }

  int a = 0;
  for(auto i : line){
    long double atualSlope = slopeLine[{i.F,{i.S.F, i.S.S}}];
    a++;
    qt[atualSlope]++;
    ans += a - qt[atualSlope];
    ans += (sz(vert) + sz(hori));
  }

  ans += (sz(vert) * sz(hori));

  cout << ans << endl;

  return 0;
}