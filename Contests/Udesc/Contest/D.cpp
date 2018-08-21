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
#define lli long long int
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


vector<pair<double, double>> vec;
int pd[201][201];

// int knap(int obj, int last){
//   if(obj == sz(vec)) return 0;
//   // if(pd[obj][last] != -1) return pd[obj][last];

//   int a = knap(obj+1, last);
//   int c = knap(obj+1, obj);

//   if(vec[obj].S < vec[last].S and vec[obj].F > vec[last].F){
//     int b = knap(obj+1, obj) + 1;
//     return pd[obj][last] = max({a, b, c});
//   }
//   return pd[obj][last] = max(a, c);
// }

int lis(){
  int lis[201];

  for(int i=0;i<sz(vec);i++) lis[i] = 1;

  int ans = 0;
  for(int i=1;i<sz(vec);i++){
    for(int j=0;j<i;j++){
      if(vec[i].F > vec[j].F and vec[i].S < vec[j].S and lis[i] < lis[j] + 1){
        lis[i] = lis[j] + 1;
      }
    }
  }

  for(int i=0;i<sz(vec);i++) ans = max(ans, lis[i]);
    return ans;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  for(int tt=0;tt<t;tt++){
    int n;
    vec.clear();
    cin >> n;
    memset(pd, -1, sizeof pd);

    for(int i=0;i<n;i++){
      double a, b;
      cin >> a >> b;
      vec.pb({a, b});
    }
    cout << lis() << endl;

  }


  return 0;
}