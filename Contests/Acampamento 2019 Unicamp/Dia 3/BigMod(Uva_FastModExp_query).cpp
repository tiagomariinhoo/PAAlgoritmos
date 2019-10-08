#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e6 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

lli modexp(lli x, lli y, lli p){
  lli ans = 1;
  while(y > 0){
    if(y&1) ans = (ans*x)%p;
    y = (y >> 1);
    x = (x*x)%p;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  lli b, p, m;
  while(cin >> b >> p >> m){
    cout << modexp(b, p, m) << endl;
  }

  return 0;
}