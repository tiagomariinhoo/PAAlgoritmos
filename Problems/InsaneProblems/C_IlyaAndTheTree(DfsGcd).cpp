#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(4*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
int c[MAXN];
vector<int> vec[MAXN];
int ans[MAXN];

void dfs(int x, int pai, int at, int tot){
  ans[x] = max(ans[x], tot);
  if(tot == 1) return ;

  for(auto i : vec[x]){
    if(i == pai) continue;
    
    if(tot == c[i]){
      dfs(i, x, at, c[i]);
      continue;
    }

    if(!at){
      dfs(i, x, 0, __gcd(tot, c[i]));
      dfs(i, x, 1, tot);
    } else {
      dfs(i, x, at, __gcd(tot, c[i]));
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++) cin >> c[i];
  for(int i=1;i<=2*n;i++) ans[i] = 1;
  ans[1] = c[1];
  for(int i=0;i<n-1;i++){
    int a, b;
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }

  dfs(1, 0, 1, 0);
  dfs(1, 0, 0, c[1]);

  for(int i=1;i<=n;i++) cout << ans[i] << " ";
  cout << endl;


  return 0;
}