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

int n, x;
vector<lli> vec;
lli pd[MAXN][4];

lli ansi = 0;
lli solve(int pos, int at){
  if(pos == sz(vec)) return 0;

  lli &ans = pd[pos][at];
  if(ans != -1) return ans;

  lli a = 0;

  if(!at){
    a = solve(pos+1, 0) + vec[pos];
    a = max(a, 0LL);
    a = max(a, solve(pos+1, 1) + (vec[pos] * x));
  } else if(at == 1){
    a = solve(pos+1, at) + (vec[pos] * x);
    a = max(a, 0LL);
    a = max(a, solve(pos+1, at+1) + (vec[pos] * x));
    a = max(a, solve(pos+1, at+1) + (vec[pos]));
  } else if(at == 2){
    a = solve(pos+1, at) + vec[pos];
    a = max(a, 0LL);
  }
  ansi = max(ansi, a);
  return ans = a;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> n >> x;

  for(int i=0;i<n;i++){
    lli a;
    cin >> a;
    vec.push_back(a);
  }

  memset(pd, -1, sizeof pd);
  lli ans = 0, maxi = 0;

  lli aa = solve(0, 1), bb = solve(0, 0);
  cout << ansi << endl;

  return 0;
}