#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(1e5 + 10)
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

string s;
int q;
int n;

int tree[4][11][11][MAXN];

void atualiza(int x, int v, char atual, int pos, int tam){
  int aq;
  if(atual == 'A') aq = 0;
  else if(atual == 'C') aq = 1;
  else if(atual == 'G') aq = 2;
  else aq = 3;
  for(;x<=n;x+=(x&-x)){
    tree[aq][pos][tam][x] += v;
  }
}

int sum(int x, char atual, int pos, int tam){
  int s = 0;
  int aq;
  
  if(atual == 'A') aq = 0;
  else if(atual == 'C') aq = 1;
  else if(atual == 'G') aq = 2;
  else aq = 3;
  
  for(;x>0;x-=(x&-x)){
    s += tree[aq][pos][tam][x];
  }
  return s;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string aux;
  cin >> aux;
  s += '*';
  for(int i=0;i<sz(aux);i++) s += aux[i];
  n = sz(s);

  vector<char> alf = {'A', 'C', 'G', 'T'};

  for(int i=1;i<sz(s);i++){
    int id = i-1;
    for(int j=1;j<=10;j++){
      for(auto k : alf){
        if(k == s[i]){
          atualiza(i, 1, k , (i)%j, j);         
        }
      }
    }
  }

  cin >> q;

  while(q--){

    int op;
    cin >> op;
    if(op == 1){
      int idx;
      char v;
      cin >> idx >> v;
      
      for(int i=1;i<=10;i++){
        atualiza(idx, -1, s[idx], (idx)%i, i);
      }
      
      s[idx] = v;

      for(int i=1;i<=10;i++){
        atualiza(idx, 1, s[idx], (idx)%i, i);
      }

    } else {
      int l, r;
      string aux;
      cin >> l >> r >> aux;
      int ans = 0;

      for(int i=0;i<sz(aux);i++){
        ans += (sum(r, aux[i], (i+l)%sz(aux), sz(aux)) - sum(l-1, aux[i], (i+l)%sz(aux),sz(aux)));
        // cout << ans << endl;
      }
      cout << ans << endl;
    }   
  }


  return 0;
}