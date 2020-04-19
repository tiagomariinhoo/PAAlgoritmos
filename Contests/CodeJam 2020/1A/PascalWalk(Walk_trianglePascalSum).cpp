#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2 * 1e5 + 1)
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

/**
 * Problema: Dado um triangulo de pascal, achar um caminho
 * que a soma de todas as celulas dá exatamente igual a N.
 * 
 * Propriedade: cada linha do triangulo de pascal é uma soma 2^i
 * Então basta tirar 50 de N (como se fosse uma margem de erro)
 * Pega as linhas dos bits setados e depois completa com 1.
 */ 

int t;
vector<vector<lli> > vec;
lli n;

void pasc() {
  while(sz(vec) < 40) {
    vector<lli> aux;
    if(!sz(vec)) {
      aux.push_back(1LL);
    } else {
      if(sz(vec) == 1LL) {
        aux.push_back(1LL);
        aux.push_back(1LL);
      } else {
        aux.push_back(1LL);
        bool at = false;
        for(int i=0;i<sz(vec[sz(vec)-1LL]) - 1LL;i++){
          lli soma = vec[sz(vec)-1LL][i] + vec[sz(vec)-1LL][i+1LL];
          if(soma >= 1e9){
            at = true;
            break;
          }
          aux.push_back(soma);
        }
        aux.push_back(1LL);
        if(at) break;
      }
    }
    vec.push_back(aux);
  }
}

bool at = false;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  pasc();

  cin >> t;
  int tt = 1;
  while(t--) {
    cin >> n;

    cout << "Case #" << tt++ << ":" << endl;
    if(n <= 499) {
      for(int i=0;i<n;i++) {
        cout << i+1 << " " << 1 << endl;
      }
      continue;
    } 

    int nn = n-50;

    vector<int> aux;
    lli somaTeste = 0;
    for(int i=0;i<32;i++) {
      if(nn & (1 << i)) {
        aux.push_back(i);
      }
    }

    int a = 0;
    lli sum = 1;
    int x = 0, y = 0;
    map<pair<int, int>, int> vis;
    cout << x+1 << " " << y+1 << endl;
    vis[{x, y}] = 1;
    while(a < sz(aux)) {
      int atual = aux[a];
      if(x == atual) {
        if(y == 0) {
          while(y < sz(vec[atual])) {
            if(!vis[{x, y}]) {
              sum += vec[x][y];
              cout << x+1 << " " << y+1 << endl;
              vis[{x, y}] = 1;
            }
            y++;
          }
          y = sz(vec[atual]) - 1;
        } else {
          while(y >= 0) {
            if(!vis[{x, y}]) {
              sum += vec[x][y];
              cout << x+1 << " " << y+1 << endl;
              vis[{x, y}] = 1;
            }
            y--;
          }
          y = 0;
        }
        a++;
      } else {
        while(x < atual) {
          if(y!=0) y++;
          x++;
          if(!vis[{x, y}]) {
            cout << x+1 << " " << y+1 << endl;
            vis[{x, y}] = 1;
            sum++;
          }
        }
      }
    }
    while(sum < n) {
      if(y == 0) {
        if(!vis[{x, y}]){
          cout << x+1 << " " << y+1 << endl;
          sum++;
        }
        x++;
      } else {
        if(!vis[{x, y}]){
          cout << x+1 << " " << y+1 << endl;
          sum++;
        }
        x++, y++;
      }
    }
    at = false;
  }


  return 0;
}