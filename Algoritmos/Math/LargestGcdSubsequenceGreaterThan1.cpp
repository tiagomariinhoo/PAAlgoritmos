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
// #define MAXN (int)1e7 * 1.5
// #define MAXL 3000

const int MAXN = 1e7*1.5 + 5;
lli prime[MAXN+1] , countdiv[MAXN+1];
int n;
vi vec;

void sieve(){
  for(int i=2;i*i<MAXN;i++){
    if(!prime[i]) for(int j=i*i;j<MAXN;j+=i) prime[j] = i;
  }
  for(int i=1;i<MAXN;i++) if(!prime[i]) prime[i] = i;
}

//Largest gcd subsequence > 1
int largestgcd(){
  lli ans = 0;
  for(lli i=0;i<n;i++){
    lli element = vec[i];
    while(element > 1){
      lli div = prime[element];
      ++countdiv[div];
      ans = max(ans, countdiv[div]);
      while(element%div==0) element/=div;
    }
  }
  return ans;
}


int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> n;
  int atual = 0;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vec.pb(a);
    if(!i) atual = a;
    else atual = __gcd(atual, a);
  }


  sieve();
  for(int i=0;i<sz(vec);i++) vec[i]/=atual;

  int ans = n - largestgcd();
  if(ans == n) cout << -1 << endl;
  else cout << ans << endl;

   return 0; 
} 