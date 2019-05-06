#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<int> vec[MAXN];
bool at = false, at2 = false;
int vis[MAXN][2];
int pai[MAXN][2];
int s;
int folha[MAXN];
pair<int, int> dp[MAXN];

int vis2[MAXN];

void dfs(int x){
  vis2[x] = 1;
  if(at2) return ;
  for(auto i : vec[x]){
    if(vis2[i] == 1) at2 = true;
    else if(vis2[i] == 2) continue;
    dfs(i);
  }
  vis2[x] = 2;
}

vector<int> ans;
void solve(int x){
  int atual = x;
  ans.push_back(x);
  int at = 1;
  while(atual != s or at != 0){
    if(at){
      atual = vis[atual][at];
      at = 0;
    } else {
      atual = vis[atual][at];
      at = 1;
    }
    ans.push_back(atual);
  }
  reverse(ans.begin(), ans.end());
  cout << "Win" << endl;
  for(auto i : ans) cout << i << " ";
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int n;
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    for(int j=0;j<a;j++){
      int b;
      cin >> b;
      vec[i].push_back(b);
    }
  }
  memset(dp, -1, sizeof dp);
  for(int i=1;i<=n;i++) if(vec[i].size() == 0) folha[i] = 1;
  cin >> s;

  dfs(s);
  queue<pair<int, int> > q;
  q.push({s, 0});
  while(!q.empty()){
    int u = q.front().F;
    int tam = q.front().S;
    q.pop();

    for(auto i : vec[u]){
      if(!vis[i][(tam+1)%2]){
        vis[i][(tam+1)%2] = u;
        q.push({i, tam+1});
      }
    }
  }

  int pos = 1;
  for(int i=1;i<=n;i++) if(vis[i][1] and folha[i]){
    at = true;
    pos = i;
    break;
  }

  if(at){
    solve(pos);
  } else if(at2){
    cout << "Draw" << endl;
  } else cout << "Lose" << endl;

  return 0;
}