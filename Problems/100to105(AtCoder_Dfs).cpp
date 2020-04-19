#include<bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int,int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

vector<int> vec = {100, 101, 102, 103, 104, 105};
int pd[100001];
bool at = false;
int x;

int solve(int atual){
  if(at) return 1;
  if(atual > x) return 0;
  if(atual == x){
    at = true;
    return 1;
  }

  if(pd[atual] != -1) return pd[atual];
  int at = 0;
  for(auto i : vec){
    at = max(at, solve(atual+i));
  }

  return pd[atual] = at;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> x;
  memset(pd, -1, sizeof pd);

  solve(0);

  if(at) cout << 1 << endl;
  else cout << 0 << endl;

  return 0;
}
