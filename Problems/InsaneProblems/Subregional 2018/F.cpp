#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
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
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 2002

int n;
vector<pair<ii, ii> > vec;
int to[MAXN];
int pd[MAXN][(1 << 11)];

/*
  Visitar todos os palcos maximizando o valor C, pode visitar os shows
  que comecem quando termina um mas tem que visitar todos os palcos
  Pd com bitmask, onde temos a posição e a mask seria os palcos visitados.
*/

int solve(int pos, int p){
  if(pos == sz(vec)){
    if(p == (1 << n) - 1) return 0;
    return -101010101;
  }
  int &ans = pd[pos][p];
  if(ans != -1) return ans;
  int a = solve(pos+1, p);
  int b = solve(to[pos], p|(1 << vec[pos].S.S)) + vec[pos].S.F; 

  return ans = max(a, b);
}

int main(){ 
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
  	int m;
  	cin >> m;
  	for(int j=0;j<m;j++){
  		int a, b, c;
  		cin >> a >> b >> c;
  		vec.pb({{a, b}, {c, i}});
  	}
  }

  memset(pd, -1, sizeof pd);

  sort(vec.begin(), vec.end());
  for(int i=0;i<sz(vec);i++) to[i] = sz(vec);


  for(int i=0;i<sz(vec);i++){
    for(int j=i+1;j<sz(vec);j++){
      if(vec[j].F.F >= vec[i].F.S){
        to[i] = j;
        break;
      }
    }
  }

  // for(int i=0;i<sz(vec);i++) cout << vec[i].F.F << " " << vec[i].F.S << " " << vec[i].S.F << " " << vec[i].S.S << endl;
  // for(int i=0;i<sz(vec);i++) cout << i << " - " << to[i] << endl;

  int ans = solve(0, 0);
  
  if(ans <= 0) cout << -1 << endl;
  else cout << ans << endl;


   return 0; 
} 