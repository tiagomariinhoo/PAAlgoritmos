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
int n, q;
vi vec;
int m, d;
lli pd[202][30][30];

lli mod(lli x, lli y){
  return (x%y + y)%y;
}

lli solve(int pos, lli sum, int atual){
  if(atual > m) return 0;
  if(pos == sz(vec))
    return (!sum and atual == m);
  
  lli &ans = pd[pos][sum][atual];
  if(ans != -1) return ans;

  ans = solve(pos+1, mod(sum+vec[pos], d), atual + 1);
  ans += solve(pos+1, sum, atual);

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  while(1){
    cin >> n >> q;
    if(!n and !q) break;
    vec.clear();
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      vec.pb(a);
    }
    cout << "SET " << k++ << ":" << endl;
    for(int i=0;i<q;i++){
      cin >> d >> m;
      memset(pd, -1, sizeof pd);
      cout << "QUERY " << i+1 << ": ";
      cout << solve(0, 0, 0) << endl;
    }

  }


  return 0;
} 