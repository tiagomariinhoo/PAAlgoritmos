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
int n, m;
vector<int> vec;
int pd[(1<<16)], vis[(1<<16)];

int solve(){

  queue<pair<int, int> > q;
  q.push({(1<<n)-1, 0});

  while(!q.empty()){
    int a = q.front().F;
    int b = q.front().S;
    q.pop();

    vis[a] = 1;
    if(a == 0) return b;

    for(auto i : vec){

      int mask = i^a;
      if(vis[mask]) continue;
      q.push({mask, b+1});
    }

  }

  return 1e8;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> t;
  int tt = 1;
  while(t--){
   cin >> n >> m; 
    vec.clear();

    // memset(pd, 10000, sizeof pd);

    for(int i=0;i<m;i++){
      int mask = 0;
      for(int j=0;j<n;j++){
        int a;
        cin >> a;
        if(a == 1) mask |= (1 << j);
      }
      // pd[mask] = 1;
      vec.push_back(mask);
    }

  memset(pd, -1, sizeof pd);
  memset(vis, 0, sizeof vis);

  int ans = solve();

   cout << "Case " << tt++ << ":" << " ";
   if(ans >= 1e8) cout << "IMPOSSIBLE" << endl;
   else cout << ans << endl;
  }

  return 0;
}