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
typedef pair<int, int> ii;
int n, m;
int c[MAXN];
vector<int> vec[MAXN];
int grau[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for(int i=0;i<n;i++) cin >> c[i];
  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    vec[b].push_back(a);
    grau[a]++;
  }

  queue<int> aux, aux2;

  for(int i=0;i<n;i++){
    if(!grau[i]){
      if(c[i]) aux.push(i);
      else aux2.push(i);
    }
  }

  bool at = true;
  int ans = 0;
  while(!aux.empty() or !aux2.empty()){
    if(at){
      while(!aux2.empty()){
        int u = aux2.front();
        aux2.pop();
        for(auto i : vec[u]){
          grau[i]--;
          if(!grau[i]){
            (c[i]) ? aux.push(i) : aux2.push(i);
          }
        }
      }

      at = false;

      if(sz(aux))
      ans++;
    } else {
      while(!aux.empty()){
        int u = aux.front();
        aux.pop();
        for(auto i : vec[u]){
          grau[i]--;
          if(!grau[i]){
            (c[i]) ? aux.push(i) : aux2.push(i);
          }
        }
      }
      at = true;
    }
  }

  cout << ans << endl;

  return 0;
}