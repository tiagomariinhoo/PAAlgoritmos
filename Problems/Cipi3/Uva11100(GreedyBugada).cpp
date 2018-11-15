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

int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool at2 = false;
  while(1){
    cin >> n;
    if(!n) break;

    if(!at2) at2 = true;
    else cout << endl;

    set<int> aux;
    vi vec;
    int maxi = 0;
    map<int, int> qt;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      vec.pb(a);
      qt[a]++;
      maxi = max(maxi, qt[a]);
      aux.insert(a);
    }
    sort(vec.begin(), vec.end());
    // for(auto i : aux) vec.pb(i);

    cout << maxi << endl;
    for(int i=0;i<maxi;i++){
      bool at = false;
      for(int j=i;j<sz(vec);j+=maxi){
        if(!at) at = true;
        else cout << " ";
        cout << vec[j];
      } cout << endl;
    }

    // vector<vi> ans;
    // int vis[n+1];
    // memset(vis, 0, sizeof vis);

    // int at = 0;
    // int a = 0;
    // while(a < n){
    //   vi auxx;
    //     for(int j=0;j<sz(vec);j++){
    //       if(!qt[vec[j]]) continue;
    //       auxx.pb(vec[j]);
    //       qt[vec[j]]--;
    //       a++;
    //     }
    //   ans.pb(auxx);
    // }

    // cout << sz(ans) << endl;
    // for(int i=0;i<sz(ans);i++){
    //   if(!sz(ans[i])) continue;
    //   for(int j=0;j<sz(ans[i]);j++){
    //     if(j) cout << " ";
    //     cout << ans[i][j];
    //   } cout << endl;
    // }

  }

  return 0;
} 