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
#define MAXN 100001
#define MAXL 20
#define MOD2 998244353

int n;
lli vec[100100];
lli pd[51005][2][200];
lli sum[200000];
lli solve(lli pos, lli ac, lli turno){
	if(pos >= n+1) return 0;
	lli &ans = pd[pos][ac][turno];
	if(ans != -1) return ans;

  lli proxi = pos + 3*turno;
  proxi = min(proxi, 51000LL);

	lli b = solve(proxi, 0, turno + 1);
  lli c = 0;
  if(sum[proxi - 1] - sum[pos-1] >= 0)
	c = solve(proxi, 1, turno + 1) + (sum[proxi - 1] - sum[pos - 1]);

	return ans = max({b, c, 0LL});
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> vec[i];
  }

  sum[1] = vec[1];
  for(int i=2;i<=n;i++){
  	sum[i] = sum[i-1] + vec[i];
  }
  for(int i=n+1;i<=n+50000;i++) sum[i] = sum[i-1];

  memset(pd, -1, sizeof pd);

  for(int i=1;i<=n;i++) solve(i, 0, 1);

  for(int i=1;i<=n;i++){
    cout << max(pd[i][0][1], pd[i][1][1]) << endl;
  }

  return 0;
}