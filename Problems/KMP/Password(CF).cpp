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

int lps[MAXN], lps2[MAXN];
string s;

/*
  Problema: Achar uma substring que seja suffix e preffix

  Usando KMP:
  Calcula LPS do Preffix e do Suffix
  Verifica as substrings no meio da string que contem isso
*/

void solve(){
  int i = 1, len = 0;
  while(i < sz(s)){
    if(s[i] == s[len]){
      lps[i] = ++len;
      i++;
    } else {
      if(len > 0) len = lps[len-1];
      else i++;
    }
  }

  reverse(s.begin(), s.end());
  
  i = 1, len = 0;
  while(i < sz(s)){
    if(s[i] == s[len]){
      lps2[i] = ++len;
      i++;
    } else {
      if(len > 0) len = lps2[len-1];
      else i++;
    }
  }

  reverse(s.begin(), s.end());
  reverse(lps2, lps2 + sz(s));

  // for(int i=0;i<sz(s);i++){
  //   cout << lps[i] << " ";
  // } cout << endl;

  // for(int i=0;i<sz(s);i++){
  //   cout << lps2[i] << " ";
  // } cout << endl;

  int l = -1, r = -1;
  for(int i=0;i<sz(s);i++){
    int atual = lps[i];
    // cout << lps[i] << " - " << lps2[i-atual+1] << endl;
    // cout << i-atual+1 << " " << i << endl;
    if(lps2[i-atual+1] == lps[i] and i-atual+1 != 0 and atual != 0){
      if(l == -1)
      l = i-atual+1, r = i;
      else if(i - (i-atual+1) > r - l) 
      l = i-atual+1, r = i;
    }
  }
  if(l != -1 and r != -1){
    for(int i=l;i<=r;i++) cout << s[i];
    cout << endl;
  } else cout << "Just a legend" << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  solve();

  return 0;
}