#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(4*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
lli pd[2002][2002][2][2];

lli solve(int l, int r, int at, int at2){
  if(l + r == n) return 0;
  lli a, b, c, d;
  a = b = c = d = -LLONG_MAX;

  lli &ans = pd[l][r][at][at2];
  if(ans != -1) return ans%MOD;

  if(l == r){
    if(!l){
      a = solve(l+1, r, 0, 0);
      b = solve(l+1, r, 1, 0);
    } else {
      a = solve(l+1, r, 1, 0) + 1;
      b = solve(l+1, r, 0, 0);
    }
    a%=MOD, b%=MOD;
    return ans = max({a, b})%MOD;
  } else {
    if(!at){
      if(l < n/2){
        a = solve(l+1, r, 1, 0) + 1;
        b = solve(l, r+1, 0, 0);

        c = solve(l+1, r, 0, 0);
        d = solve(l, r+1, 1, 0) + 1;
        a%=MOD, b%=MOD, c%=MOD, d%=MOD;
        return ans = max({a+b, c+d})%MOD;
      } else {
        a = solve(l, r+1, 0, 0);
        b = solve(l, r+1, 1, 0) + 1;
        a%=MOD, b %= MOD;
        return ans = max({a, b})%MOD;
      }
    } else {
      if(l < n/2){
        a = solve(l+1, r, 0, 0);
        b = solve(l, r+1, 0, 0);
        a%=MOD, b%=MOD;
        return ans = (a + b)%MOD;
      } else {
        a = solve(l, r+1, 0, 0);
        a%=MOD;
        return ans = a;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  n *= 2;

  memset(pd, -1, sizeof pd);
  
  cout << solve(0, 0, 0, 0) << endl;

  return 0;
}