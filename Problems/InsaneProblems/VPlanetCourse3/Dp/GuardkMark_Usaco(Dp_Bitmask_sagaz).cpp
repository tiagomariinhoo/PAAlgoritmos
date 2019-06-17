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
typedef pair<lli,lli> ii;

lli n, h;
vector<pair< lli, pair<lli , lli > > > vec;
lli we[(1 << 20)], he[(1 << 20)];
lli dp[(1 << 20)];

/*
    Gera todas as possibilidades
    Dp e bitmask
    na hora de calcular a dp, tenta inserir o elemento na base
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

  cin >> n >> h;
  for(int i=0;i<n;i++){
    int a, b, c;
     cin >> a >> b >> c;
     vec.push_back({a, { b, c}});
  }

  for(int i=0;i<=(1 << n);i++){
    dp[i] = -INT_MAX;
    for(int j=0;j<n;j++){
      if(i&(1 << j)){
        we[i] += vec[j].S.F;
        he[i] += vec[j].F;
      }
    }
  }
    
  lli ans = -1;

  for(int i=0;i<n;i++) dp[(1 << i)] = vec[i].S.S;
  // dp[0] = INT_MAX;

  for(int j=0;j<(1 << n);j++){
    for(int i=0;i<n;i++){
      if((1 << i)&j) continue;
      int atual = ((1 << i)|(j));
      dp[atual] = max({dp[atual], min({vec[i].S.S, dp[j] - vec[i].S.F})});
      if(he[atual] >= h) ans = max(ans, dp[atual]);
    }
  }
  
  if(ans == -1) cout << "Mark is too tall" << endl;
  else cout << ans << endl;

  return 0;
}