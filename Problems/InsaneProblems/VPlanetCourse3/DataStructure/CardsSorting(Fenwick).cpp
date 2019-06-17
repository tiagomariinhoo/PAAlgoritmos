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

int n;
vector<int> vec;
int tree[MAXN];
set<int> pos[MAXN], menor;
int qt[MAXN];

void atualiza(int x, int v){
  for(;x<=n;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
  if(x < 0) return 0;

  int s = 0;
  for(;x>0;x-=(x&-x)) s += tree[x];
  return s;
}

void solve(){

  int aux = -1;
  lli ans = 0;

  for(auto i : menor){
    while(!pos[i].empty()){
      int aux2;
      if(aux == -1){
      aux2 = *pos[i].begin();
      ans += (aux2);

      } else {
        aux2 = *pos[i].lower_bound(aux);
        if(aux2 < aux) aux2 = *pos[i].begin();

        if(aux2 > aux){
          ans += (aux2 - aux + 1) - (sum(aux2) - sum(aux-1));
        } else {
          ans += (n - aux + aux2 + 1 - (sum(n) - sum(aux-1) + sum(aux2)));
        }

      }

      aux = aux2;
      pos[i].erase(aux);
      atualiza(aux2, 1);
    }
  }

  cout << ans << endl;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vec.push_back(a);
    qt[a]++;
    menor.insert(a);
    pos[a].insert(i+1);
  }

  solve();

  return 0;
}