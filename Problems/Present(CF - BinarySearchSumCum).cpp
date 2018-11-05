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
#define MAXN 100001
#define MAXL 20

int n,m,w;
lli a[MAXN];
lli tree[MAXN*4], lazy[4*MAXN], tree2[4*MAXN];

bool can(lli atual){

  lli mm = m;
  lli aux[MAXN+1];
  lli cum = 0;
  memset(aux, 0, sizeof aux);
  for(int i=1;i<=n;i++){
    if(aux[i]) cum += aux[i];
    lli value = a[i] + cum;
    if(value < atual){
      if(mm < (atual - value)){
        return false;
      }
      mm -= (atual - value);
      cum += (atual - value);
      aux[min(i+w, n+1)] -= (atual - value);
    }
  }
  return true;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> n >> m >> w;

  for(int i=1;i<=n;i++) cin >> a[i]; 
  
  lli com = 1, fim = 1e18;
  while(com < fim){
    lli mid = (com + fim + 1) >> 1;
    if(can(mid)) com = mid;
    else fim = mid - 1;
  }

  cout << com << endl;

  return 0;
}