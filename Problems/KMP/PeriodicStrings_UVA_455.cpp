#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(1e6 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
typedef pair<lli,lli> ii;

string txt, pat;
int lps[MAXN];

void compLps(){
  int i = 1, len = 0;
  while(i < sz(pat)){
    if(pat[i] == pat[len]){
      lps[i] = ++len;
      i++;
    } else {
      if(len > 0) len = lps[len-1];
      else i++;
    }
  }
}

bool kmp(){
  int i = 0, j = 0;
  int ans = 0;
  while(i < sz(txt)){
    if(txt[i] == pat[j]){
      i++,j++;
    } else {
      if(j > 0) j = lps[j-1];
      else i++;
    }
    if(j == sz(pat)){
      ans++;
      // j = lps[j-1];
      j = 0;
    }
  }
  // cout << txt << " - " << pat << endl;
  // cout << ans << endl;
  if(ans*sz(pat) == sz(txt)) return true;

  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    cin >> txt;
    bool at = false;
    pat = "";
    for(int i=0;i<sz(txt);i++){
      pat += txt[i];
      for(int j=0;j<sz(pat)+1;j++) lps[j] = 0;
      compLps();
      if(kmp()){
        cout << i+1 << endl;
        at = true;
        break;
      }
    }
    if(!at) cout << sz(txt) << endl;

    if(t) cout << endl;
  }

  return 0;
}