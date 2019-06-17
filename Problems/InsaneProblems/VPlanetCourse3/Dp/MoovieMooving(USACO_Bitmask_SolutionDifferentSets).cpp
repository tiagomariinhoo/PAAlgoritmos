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
typedef pair<int,int> ii;

int n, h;
lli d[21];
lli pd[(1 << 21)];
vector<lli> vec[22];
vector<lli> values[22];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("movie.in", "r", stdin);
  // freopen("movie.out", "w", stdout);

  cin >> n >> h;
  for(int i=0;i<n;i++){
    cin >> d[i];
    int m;
    cin >> m;
    for(int j=0;j<m;j++){
      int a;
      cin >> a;
      vec[i].push_back(a);
    }
  }

  int ans = -1;
  for(int i=0;i<n;i++){
    pd[(1 << i)] = (vec[i][0] == 0 ? d[i] : 0);
  }

  for(int i=0;i<=(1 << n);i++){
    int tam = __builtin_popcount(i);
    values[tam].push_back(i);
  }

  for(int i=0;i<=n;i++){
    if(sz(values[i]) > 0)
    for(auto j : values[i]){  
      if(pd[j] != 0)
      for(int k=0;k<n;k++){
        if(!((1 << k)&j)){
          int idx = (1 << k)|j;
          lli atual = pd[j];
          int idx2 = lower_bound(vec[k].begin(), vec[k].end(), atual) - vec[k].begin();
          if(vec[k][idx2] <= atual){
            if(vec[k][idx2] + d[k] >= atual) pd[idx] = (vec[k][idx2] + d[k]);
          } else {
            if(idx2 > 0) idx2--;
            if(vec[k][idx2] <= atual) pd[idx] = max(pd[idx], vec[k][idx2] + d[k]);
          }
        }
      }
    }
  }

  for(int i=0;i<=(1 << n);i++){
    if(pd[i] >= h)
     if(ans == -1) ans = __builtin_popcount(i);
     else ans = min(ans, __builtin_popcount(i));
  }
  
  cout << ans << endl;

  return 0;
}