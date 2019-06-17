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
typedef pair<lli,lli> ii;

lli n;
vector<pair<ii, ii> > vec;
lli dp[101][2002];

/*
  Ordena e aplica knap normal

  Pra recuperar o item, começa com a resposta completa
  Se o proximo indice na pd, muda a resposta, então vc colocou ele
  Coloca ele na resposta. Genial (Reco Function)
*/  

lli solve(int pos, int tempo){
  if(pos == n) return 0;

  lli &ans = dp[pos][tempo];
  if(ans != -1) return ans;

  lli a = 0;
  if(tempo + vec[pos].F.F < vec[pos].F.S){
    a = solve(pos+1, tempo + vec[pos].F.F) + vec[pos].S.F;
    a = max(a, solve(pos+1, tempo));
  } else a = solve(pos+1, tempo);
  return ans = a;
}

vector<int> posAns;

void reco(int pos, int ans, int tempo){
  if(pos == n) return ;
  if(solve(pos+1, tempo) == ans){
    reco(pos+1, ans, tempo);
  } else {
    posAns.push_back(pos);
    reco(pos+1, ans - vec[pos].S.F, tempo + vec[pos].F.F);
  }
}

bool comp(pair<ii, ii> a, pair<ii, ii> b){
  if(a.F.S == b.F.S) return a.F.F < b.F.F;
  return a.F.S < b.F.S; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a, b, c;
    cin >> a >> b >> c;
    vec.push_back({{a, b}, {c, i}});
  }

  memset(dp, -1, sizeof dp);

  sort(vec.begin(), vec.end(), comp);

  cout << solve(0, 0) << endl;
  reco(0, solve(0,0), 0);
  cout << sz(posAns) << endl;
  for(auto i : posAns){
    cout << vec[i].S.S + 1 << " ";
  } cout << endl;

  return 0;
}