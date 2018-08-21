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

int ans[11];

void pre(){
  vi vec;
  vec.pb(1), vec.pb(2), vec.pb(4), vec.pb(5), vec.pb(7), vec.pb(8), vec.pb(10);
  vec.pb(11);

  for(int i=0;i<sz(vec);i++){
    int a = 11;
    int x = vec[i];
    int ii = i;
    int aux = 0;
    while(x < 11){
      int jj = 0;
      int p = 0;
      for(int j=sz(vec)-1;j>=0;j--){
        jj = j;
        if(vec[j] == x) break;
        p++;
      }
      aux += (p*2);
      
      ii++;
      x = vec[ii];
    }
    ans[vec[i]] = aux;
  }

  ans[9] = ans[8];
  ans[6] = ans[5];
  ans[3] = ans[2];
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();

  while(1){
    int n;
    cin >> n;
    if(n == -1) break;

    cout << ans[n] << endl;
  }

  return 0;
}