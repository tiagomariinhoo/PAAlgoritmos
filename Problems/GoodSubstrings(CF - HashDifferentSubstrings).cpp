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

string s;
map<char,int> c;
int k;
set<string> can;

void countSubstrings(){
  int n = sz(s);
  int p = 31;
  int m = 1e9 + 9;
  vector<lli> p_pow(n);

  p_pow[0] = 1;
  for(int i=1;i<n;i++)
    p_pow[i] = (p_pow[i-1]*p)%m;

  vector<lli> h(n+1, 0);
  for(int i=0;i<n;i++) h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i])%m;

  int sum[n+2];
  memset(sum, 0, sizeof sum);
  sum[1] = (c[s[0]] == 0);
  for(int i=1;i<sz(s);i++){
    sum[i+1] += sum[i] + (c[s[i]] == 0);
  }

  int cnt = 0;
  for(int l=1;l<=n;l++){
    set<lli> hs;
    for(int i=0;i<=n-l;i++){
      lli cur_h = (h[i+l] + m - h[i])%m;
      cur_h = (cur_h * p_pow[n-i-1])%m;
      if(sum[i+l] - sum[i] <= k)
      hs.insert(cur_h);

    }
    cnt += sz(hs);
  }
  cout << cnt << endl;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  string aa;
  cin >> aa;
  int ii = 'a';
  for(int i=0;i<sz(aa);i++){
    c[ii++] = aa[i] - '0';
  }

  cin >> k;

  countSubstrings();

  return 0;
}