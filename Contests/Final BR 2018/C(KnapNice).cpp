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
// typedef pair<int,int> ii;
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
vector<pair<int,int>> vec;
double pd[10010][8][125];

double solve(int pos, int qt, int disp){
  if(pos == vec.size()) return 0;

  disp = min(disp, 120);
  double &ans = pd[pos][qt][disp];
  if(ans != -1) return ans;

  double a = DBL_MAX, b = DBL_MAX;
  if(disp == 120){
    a = solve(pos + 1, 2, vec[pos].first) + vec[pos].second;
  } else {
    if(qt == 2){
      a = solve(pos + 1, qt + 1, disp + vec[pos].first) + vec[pos].second*(0.5);
      b = solve(pos + 1, 2, vec[pos].first) + vec[pos].second;
    } else if(qt <= 6){
      a = solve(pos + 1, qt + 1, disp + vec[pos].first) + vec[pos].second*(0.25);
      b = solve(pos + 1, 2, vec[pos].first) + vec[pos].second;
    } else {
      a = solve(pos + 1, 2, vec[pos].first) + vec[pos].second;
    }
  }


  return ans = min(a, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a, b;
    cin >> a >> b;
    vec.push_back({a, b});
  }
  for(int i=0;i<=10009;i++) for(int j=0;j<=7;j++) for(int k=0;k<=123;k++) pd[i][j][k] = -1;
  double ans = solve(1, 2, vec[0].first) + vec[0].second;
  printf("%.2lf\n", ans);

  return 0;
} 