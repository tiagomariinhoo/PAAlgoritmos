#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

lli value = 1e18;
set<lli> like;
set<lli> dontLike;
int n;
bool at = false;

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int t, m;
    cin >> t >> m;
    vector<lli> aux;
    if(t == 1){
      for(int j=0;j<m;j++){
        lli a;
        cin >> a;
        aux.pb(a);
      }
      vector<lli> aux2;
      if(sz(like) != 0){
        for(int j=0;j<sz(aux);j++){
          if(dontLike.find(aux[j]) != dontLike.end()) continue;
          if(like.find(aux[j]) != like.end()) aux2.pb(aux[j]);
        }
        like.clear();
        for(int j=0;j<sz(aux2);j++) like.insert(aux2[j]);
      } else {
        for(int j=0;j<sz(aux);j++){
          if(dontLike.find(aux[j]) != dontLike.end()) continue;
          if(at) continue;
          like.insert(aux[j]);
        }
      } 

      at = true;
    } else {
      for(int j=0;j<m;j++){
        lli a;
        cin >> a;
        dontLike.insert(a);
        if(like.find(a) != like.end()) like.erase(a);        
      }
    }
  }

  if(sz(like) == 0){
    if(!at){
      cout << value - sz(dontLike) << endl;
    } else cout << 0 << endl;
  } else {
    cout << sz(like) << endl;
  }


  return 0;
}