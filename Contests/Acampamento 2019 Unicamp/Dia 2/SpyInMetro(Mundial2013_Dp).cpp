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

/*
Problema:
Dado N estações
Tempo T que tem que estar na última estação
Todos os tempos de saída de trem da primeira estação
Todos os tempos de saída de trem da última estação
Pode se deslocar pra qualquer estação
Minimizar o tempo ficado em cada estação (ficar o maximo de tempo nos trens)

Solução:
Pre calcula os tempos que terá trem em cada estação
Faz uma DP pra verificar se é melhor ir ou voltar pra alguma estação

*/

int n, t;
vector<int> travel(51);
vector<int> m1, m2;

int dp[51][201];
vector<int> preIndo[51];
vector<int> preVoltando[51];

void read(){
  cin >> n;
  if(!n) exit(0);

  cin >> t;

  m1.clear(), m2.clear();
  for(int i=0;i<=n;i++) for(int j=0;j<=t;j++) dp[i][j] = -1;
  
  for(int i=0;i<n-1;i++) cin >> travel[i];
  int mm1, mm2;
  cin >> mm1;
  for(int i=0;i<mm1;i++){
    int a;
    cin >> a;
    m1.push_back(a);
  }
  cin >> mm2;
  for(int i=0;i<mm2;i++){
    int a;
    cin >> a;
    m2.push_back(a);
  }
}

void preComp(){
  
  for(int i=0;i<=n;i++) preIndo[i].clear(), preVoltando[i].clear();

  for(auto i : m1){
    int j = 0;
    int sum = i;
    while(j < n){
      if(!j) preIndo[j].push_back(sum), sum += travel[j];
      else preIndo[j].push_back(sum), sum += travel[j];
      j++;
    }
  }

  for(auto i : m2){
    int j = n-1;
    int sum = i;
    while(j >= 0){
      if(j) preVoltando[j].push_back(sum), sum += travel[j-1];
      else preVoltando[j].push_back(sum);
      j--;
    }
  }
}

int solve(int pos, int tempo){
  if(tempo > t) return 1e6;
  if(tempo == t and pos == n-1) return 0;

  if(dp[pos][tempo] != -1) return dp[pos][tempo];

  int b = 1e6;
  if(pos == n-1){
    b = (t - tempo);
    for(auto i : preVoltando[pos]){
      if(i >= tempo){
        b = min(b,
        solve(pos-1, tempo+travel[pos-1]+(i-tempo)) + (i-tempo)
        );
      }
    }
  } else {
      for(auto i: preIndo[pos]){
        if(i >= tempo){
          b = min(b,
          solve(pos+1, tempo+travel[pos] + (i-tempo)) + (i-tempo)
          );
        }
      }

      if(pos > 0){
        for(auto i: preVoltando[pos]){
          if(i >= tempo){
            b = min(b,
            solve(pos-1, tempo+travel[pos-1] + (i-tempo)) + (i-tempo)
            );
          }
        }
      }

  }

  return dp[pos][tempo] = b;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int tt = 1;
  while(1){
    read();
    preComp();
    int ans = solve(0, 0);
    cout << "Case Number " << tt++ << ": ";
    if(ans >= 1e6) cout << "impossible" << endl;
    else cout << ans << endl;
  }

  return 0;
}