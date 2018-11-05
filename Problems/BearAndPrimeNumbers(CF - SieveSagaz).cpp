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
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 10000000
#define MAXL 20
#define MOD2 998244353

int n, m;
int at[10000001];
int at2[10000001];
// int qt[10000001];

void build(){
  for(int i=2;i<=10000000;i++){
    if(!at[i])
      // if(qt[i]) at2[i]+=qt[i];
      for(int j=2;i*j<=10000000;j++){
          at[i*j]++;
        if(at2[i*j]){
          at2[i]+=at2[i*j];
        }
      }
  }
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    at2[a]++;
  }

  build();

  for(int i=1;i<=10000000;i++){
    if(at[i]) at2[i] = 0;
    at2[i] += at2[i-1];
  }

  cin >> m;
  for(int i=0;i<m;i++){
    lli l, r;
    cin >> l >> r;
    l = min(l, 10000000LL), r = min(r, 10000000LL);
    cout << at2[r] - at2[l-1] << endl;
  }

  return 0;
}