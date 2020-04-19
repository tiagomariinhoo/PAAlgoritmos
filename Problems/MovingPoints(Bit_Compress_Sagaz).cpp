#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2 * 1e5 + 1)
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

struct FenwickTree{
  // Index [0..n-1]
  // Para mudar para [1..n], coloca r > 0 e idx <= n

  vector<lli> bit;
  int n;

  FenwickTree(int n){
    this->n = n;
    bit.assign(n, 0);
  }

  lli sum(int r){
    lli ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];

    return ret;
  }

  lli sum(int l, int r){
    return sum(r) - sum(l - 1);
  }

  void add(int idx, int delta){
    for (; idx < n; idx = idx | (idx + 1))
      bit[idx] += delta;
  }
};

/**
 * Problema:
 * Dado n posições Xi e n velocidades Vi
 * Achar a soma entre todos os pares de menor distância
 * 
 * É possível notar que se tem um xi < xj e vi > vj, então a distância é 0
 * em algum momento.
 * 
 * O problema agora é achar as somas onde xi < xj e vi <= vj.
 * Para cada xi, eu pego o número de posições com vi >= vj
 * 
 * Como nós ordemaos o vector de pair
 * Iterar por ele em ordem crescente, já garante a ordem
 */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, int> > vec(n+1);
  vector<int> aux;

  vec.resize(n);

  for(int i=0;i<n;i++) cin >> vec[i].F;
  for(int i=0;i<n;i++) cin >> vec[i].S;

  sort(vec.begin(), vec.end());

  FenwickTree cnt(n), soma(n);

  for(auto i : vec) aux.push_back(i.S);

  sort(aux.begin(), aux.end());

  lli ans = 0;
  for(auto i : aux) cout << i << " ";
  cout << endl;
  for(auto i : vec) {
    int pos = lower_bound(aux.begin(), aux.end(), i.S) - aux.begin();
    cout << i.S << " - " << pos << endl;
    cout << i.F << endl;
    ans += (cnt.sum(pos) * i.F) - soma.sum(pos);

    cnt.add(pos, 1);
    soma.add(pos, i.F);
  }

  cout << ans << endl;

  return 0;
}