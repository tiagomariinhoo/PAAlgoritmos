#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2 * 1e5 + 5)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, m;
vector<lli> vec;

/**
 * Problema: Tenho M estudantes e 
 * Um caminho de N posições
 * Cada posição pode ter uma quantidade Ai 
 * de pylons, Mover o estudante pra  frente
 * Ou remover um pylon, cada ação dessa
 * toma um segundo. Tempo minimo para 
 * remover todos os Pylons do caminho
 * 
 * Solução: Busca Binária na resposta
 * Para cada tentativa de resposta
 * Faz o guloso: Pega um estudante
 * e pega o pylon mais a direita, tenta
 * tirar o máximo possível, se tirar todos
 * e ainda sobrar tempo, ele poderia
 * ter tirado alguns do anterior. Vai
 * fazendo esse guloso até que consiga
 * fazer a resposta
 */ 

bool solve(lli atual) {

  int mm = m;
  vector<lli> aux = vec;
  int i = sz(vec) - 1;
  while(mm) {
  lli temp = 0;
  bool at = false;
    while(i >= 0) {
      if(aux[i] == 0) i--;
      else {
        if(!at) temp = i + 1, at = true;
        if(temp < atual) {
          lli resto = min(aux[i], atual - temp);
          aux[i] -= resto;
          temp += resto;
          if(aux[i] == 0) i--;
        } else {
          break;
        }
      }
    }

    mm--;
  }

  // cout << "Atual : " << atual << endl;
  // for(auto i : aux) cout << i << " ";
  // cout << endl;

  for(int i=0;i<sz(aux);i++) if(aux[i] > 0) return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  for(int i=0;i<n;i++) {
    lli a;
    cin >> a;
    vec.push_back(a);
  }

  lli ans = 0;
  
  int mm = m;
  lli resto = 0;

  lli com = 0, fim = 1e17;

  int j = 0;
  while(com < fim) {
    lli mid = (com + fim) >> 1;
    if(solve(mid)) fim = mid;
    else com = mid + 1;
    j++;
  }

  cout << fim << endl;

  return 0;
}