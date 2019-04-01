#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 1)
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
string s;
int pd[501][501];

int solve(int l, int r){
  if(l == r) return 1;
  if(l > r) return 0;

  int &ans = pd[l][r];
  if(ans != -1) return ans;

  int a = INT_MAX;

  if(s[l] == s[l+1] or s[l] == s[r]) a = solve(l+1, r);
  else {
    a = min(a, solve(l+1, r) + 1);
  }
  for(int i=l+1;i<r;i++){
    if(s[i] == s[l]){
      a = min(a, solve(l, i) + solve(i+1, r));
    }
  }


  return ans = a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> s;

  memset(pd, -1, sizeof pd);

  cout << solve(0, n-1) << endl;

  return 0;
}