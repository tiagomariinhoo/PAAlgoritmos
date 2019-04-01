#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<char> vec;
lli pd[5001][5001];

lli solve(int pos, int lv){
  if(pos == vec.size() - 1) return 1;
  lli &ans = pd[pos][lv];
  if(ans != -1) return ans;

  lli a = 0;
  if(vec[pos] == 'f'){
    a = solve(pos+1, lv+1)%MOD;
  } else{
    a = solve(pos+1, lv)%MOD;
  } 

  if(lv and vec[pos] == 's') a += solve(pos, lv-1)%MOD;

  return ans = a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    char a;
    cin >> a;
    vec.push_back(a);
  }

  memset(pd, -1, sizeof pd);

	solve();

  return 0;
}