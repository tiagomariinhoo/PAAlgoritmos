#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e6 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int t;
lli pd[31][31][51];

/*
  Quebrar o chocolate horizontalmente ou verticalmente
  Tentar quebrar o minimo possível pra conseguir comer 
  exatamente K quadradinhos

  Dp, tenta quebrar verticalmente e horizontalmente
  de todas as formas

  separando a dp:
  solve(i, m, j) + solve(n-i, m, k-j)

  Eu posso separar o K que eu preciso usar
  de maneira certa pros dois lados

  Então basta pegar a resposta mínimo de qualquer corte possível
  recursivamente e gg

*/

lli solve(int n, int m, int k){
  if((k == 0) or (n*m == k)) return 0;
  if(n*m < k) return INT_MAX;

  lli &ans = pd[n][m][k];
  if(ans != -1) return ans;

  lli aa = INT_MAX;
  for(int i=1;i<n;i++){
    for(int j=0;j<=k;j++){
      aa = min({aa,
        m*m + solve(i, m, j) + solve(n-i, m, k-j)
      });
    }
  }

  for(int i=1;i<m;i++){
    for(int j=0;j<=k;j++){
      aa = min ({aa,
        n*n + solve(n, i, j) + solve(n, m-i, k-j)
      });
    }
  }

  return ans = aa;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  memset(pd, -1, sizeof pd);
  while(t--){
    int n, m, k;
    cin >> n >> m >> k;

    cout << solve(n, m, k) << endl;

  }
 

  return 0;
}