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

lli pd[71][2][2][10];
int n;
string s;

lli solve(int obj, int can, int dec, int last){
  if(obj == n) return 1;
  lli &ans = pd[obj][can][dec][last];
  if(ans != -1) return ans; 
  lli aux = 0;
  if(!dec){
    if(!can){
      int atual = s[obj] - '0';
      for(int i=0;i<=atual;i++){
        aux += solve(obj+1, i != atual, i < last, i);
      }
    } else {
      for(int i=0;i<=9;i++){
        aux += solve(obj+1, can, i < last, i);
      }
    }
  } else {
    if(!can){
      int atual = min(last, s[obj] - '0');
      for(int i=0;i<=atual;i++) aux += solve(obj+1, i != s[obj] - '0', 1, i);
    } else {
      for(int i=0;i<=last;i++) aux += solve(obj+1, 1, 1, i);
    }
  }
  return ans = aux;
}

bool check(){
  bool at = false;
  // cout << s << endl;
  for(int i=1;i<sz(s);i++){
    if(s[i] < s[i-1]) at = true;
    else if(at and s[i] > s[i-1]) return false;
  }
  return true;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    cin >> s;
    n = sz(s);
    if(!check()){
      cout << -1 << endl;
      continue;
    }
    memset(pd, -1, sizeof pd);
    cout << solve(0, 0, 0, 0) - 1 << endl;
  }

  return 0;
}