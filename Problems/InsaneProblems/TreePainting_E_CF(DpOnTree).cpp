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
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<int> vec[MAXN];
int tam[MAXN];
lli ans[MAXN];
lli tot = 0;

/*
  Calcula o tamanho de cada componente começando de 1 (por simplicidade)

  E calcula a resposta total começando de 1

  Quando você passa pro node 2, por exemplo, vc atualiza a resposta
  como se tivesse começando de 2 da seguinte forma: 
  ans[2] = ans[1] + n - 2*tam[u]
  + n : pois estamos começando de 2 agora
  - 2*tam[u]: pois tiramos tam[u] pois estamos passando de 1 pra 2
              e tiramos tam[u] de novo pois agora estamos começando de u
              então por isso somamos 'n'.

 */

void dfs(int x, int pai){
  tam[x] = 1;

  for(auto i : vec[x]){
    if(i == pai) continue;
    (dfs(i, x));
    tam[x] += tam[i];
  }
  tot += tam[x];
}

void dfs2(int x, int pai){
  if(x != pai){
    ans[x] = ans[pai] + n - 2*tam[x];
  }

  for(auto i : vec[x]){
    if(i == pai) continue;
    dfs2(i, x);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);  

  cin >> n;
  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  dfs(1, 1);
  ans[1] = tot;
  dfs2(1, 1);
  for(int i=1;i<=n;i++) tot = max(ans[i], tot);

  cout << tot << endl;

  return 0;
}