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

string s;
lli dp[(MAXN)];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> s;

  // 1 - Guarda todas as masks disponiveis na string

  for(int i=0;i<sz(s);i++){
    int mask = 0;
    for(int j=i;j<sz(s);j++){

      int atual = s[j] - 'a';

      if(mask&(1 << atual)) break;

      mask |= (1 << atual);
      dp[mask] = __builtin_popcount(mask);
    }
  }
  /*
  Verifica todas as submasks
  Se 000111 é uma mask, 000101 é uma submask
  Isso é bom porque na hora de calcular a dp
  é possível pegar uma boa resposta sem acessar a submask
  */

  for(int i=0;i<(1 << 20);i++){
    for(int j=0;j<20;j++){
      if(i & (1 << j)){
        int comp = (i ^ (1 << j));
        dp[i] = max(dp[i], dp[comp]);
      }
    }
  }

  /*
  Agora que tem em todas as masks, as melhores respostas
  (sendo a mask setada ou as submasks)
  basta atualizar a resposta
  */

  lli ans = 0;
  for(int i=0;i<(1<<20);i++){
    int mask = 0;

    for(int j=0;j<20;j++){
      if((i&(1 << j)) == 0){
        mask |= (1 << j);
        ans = max(ans, dp[i] + dp[mask]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}