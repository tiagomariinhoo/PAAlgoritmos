#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353  
#define lli long long int
#define sz(a) int(a.size())
#define M_PI 3.1415
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, a, b, k;
 
lli dp[5002][5002];

/*

  Problema:
    Dado um andar de começo: a, você pode fazer K movimentos
    Tal que o novo andar escolhido é: abs(x-y) < abs(x-b), 
    onde y é o novo andar escolhido e B é o andar que vc não pode ir

    Usando DP bottom up:
    dp[0][a] = 1, já que no movimento 0, você começa no andar A, então
    vc consegue chegar nele = 1

    d = distancia maxima que você pode fazer, partindo de 'i'
    mini = você pode ir até max(i-d+1, 1);
    maxi = voce pode ir até min(i+d-1, n);

    Então faz a soma parcial no proximo passo:
    dp[j+1][mini] += dp[j][i];
    dp[j+1][maxi+1] -= dp[j][i];

    depois tira ele mesmo de cada um dp[j+i][i] -= dp[j][i];
    Já que vc não pode ir para o mesmo andar

 */
 
lli modSum(lli a, lli b){
  a += b;
  while(a >= MOD) a -= MOD;
  while(a < 0) a += MOD;
  return a;
}

void solve(){

  //no passo 0, só estamos em A
  dp[0][a] = 1;

  for(int j=0;j<k;j++){

    for(int i=1;i<=n;i++){
    if(i == b) continue;
      int d = (abs(i-b));
      int mini = max(i-d+1, 1); //Maximo que pode ir partindo de i pra baixo
      int maxi = min(i+d-1, n); //Maximo que pode ir partindo de i pra cima
      // cout << i << " : " << mini << " - " << maxi << endl;
      // cout << dp[j][i] << endl;

      //Adiciona a resposta nesse intervalo no proximo passo
      dp[j+1][mini] = modSum(dp[j+1][mini], dp[j][i]);
      dp[j+1][maxi+1] = modSum(dp[j+1][maxi+1], -dp[j][i]);
      //Somas parciais
      //Adiciona x no [1] e -x [3], por exemplo
      //Então: 0 x x 0... 
    }

    //Faz a soma parcial
    for(int i=1;i<=n;i++){
      dp[j+1][i] = modSum(dp[j+1][i], dp[j+1][i-1]);
      // cout << dp[j+1][i] << " ";
    }

    //Tira ele mesmo em cada posição pra não contar que ele foi pro mesmo andar
    for(int i=1;i<=n;i++){
      dp[j+1][i] = modSum(dp[j+1][i], -dp[j][i]);
      // cout << dp[j+1][i] << " ";
    }
  }

  lli ans = 0;
  for(int i=1;i<=n;i++){
    ans += (dp[k][i]), ans %= MOD;
  } 

  cout << ans%MOD << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >> a >> b >> k;

  solve();

  return 0;
}