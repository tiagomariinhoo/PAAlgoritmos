#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100010
#define MAXL 20
#define MOD2 998244353

int n, m;
vector<int> vec[501];

void solve(int l, int r){

  int ans = 0;
  for(int i=0;i<n;i++){
    int atual = lower_bound(vec[i].begin(), vec[i].end(), l) - vec[i].begin();
    if(vec[i][atual] >= l){
      int com = 0, fim = min(n, m);
      while(com < fim){
        int mid = (com + fim + 1) >> 1;
        if(i + mid >= n or atual + mid >= m){
          fim = mid - 1;
          continue;
        }

        if(vec[i+mid][atual+mid] <= r) com = mid;
        else fim = mid - 1;

      }
      if(vec[i+com][atual+com] <= r and i+com < n and atual+com < m){
        ans = max({ans, com+1});
      } 
    }
  }

  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(1){
    cin >> n >> m;
    if(!n and !m) break;

    for(int i=0;i<500;i++) vec[i].clear();

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int a;
        cin >> a;
        vec[i].pb(a);
      }
    }

    int q;
    cin >> q;
    for(int i=0;i<q;i++){
      int a, b;
      cin >> a >> b;
      solve(a, b);
    }
    cout << "-" << endl;
  }


  return 0;
} 