#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353  
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

string s,t;
int pd[3002][3002];

void read(){
  cin >> s >> t;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  read();

  for(int i=0;i<=sz(s);i++){
    for(int j=0;j<=sz(t);j++){
      if(i == 0 or j == 0){
        pd[i][j] = 0;
      }
      else if(s[i-1] == t[j-1]){
        pd[i][j] = pd[i-1][j-1] + 1;
      } else {
        pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
      }
    }
  }


  string ans = "";

  int i = sz(s), j = sz(t);

  while(i > 0 and j > 0){
    if(s[i-1] == t[j-1]){
      ans += (s[i-1]);
      i--, j--;
    } else if(pd[i-1][j] > pd[i][j-1]) i--;
    else j--;
  }

  reverse(ans.begin(), ans.end());
  // ans.resize(sz(ans)-1);
  cout << ans << endl;

  return 0;
}