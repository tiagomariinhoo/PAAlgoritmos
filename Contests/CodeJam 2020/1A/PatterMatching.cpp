#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2 * 1e5 + 1)
#define MAXL 20
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if (0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int, int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int t;

/**
 *
 * Solução : Basta construir uma string
 * Checando apenas o sufixo e o prefixo
 * O conteudo do meio é só concatenar
 */

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  int tt = 1;
  while(t--) {
    int n;
    cin >> n;
    vector<string> vec;
    string maior;
    for(int i=0;i<n;i++) {
      string s;
      cin >> s;
      vec.push_back(s);
    }

    string pref = "";
    string suf = "";
    string meio = "";

    bool at2 = false;
    for(auto atual : vec) {
      string aa = "", bb = "", cc = "";
      int l = 0,r = 0;
      // Get pre
      for(int i=0;i<sz(atual);i++) {
        if(atual[i] == '*') {
          l = i;
          break;
        }
        aa += atual[i];
      }

      // Get suf
      for(int i=sz(atual)-1;i>=0;i--) {
        if(atual[i] == '*') {
          r = i;
          break;
        }
        cc += atual[i];
      }
      reverse(cc.begin(), cc.end());

      // Get mid
      for(int i=l+1;i<=r-1;i++) {
        if(atual[i] != '*') {
          bb += atual[i];
        }
      }

      meio += bb;

      // Check pref
      if(sz(pref) == 0) pref = aa;
      else {
        for(int i=0;i<min(sz(pref), sz(aa));i++) {
          if(pref[i] != aa[i]) {
            at2 = true;
            break;
          }
        }

        if(!at2) {
          if(sz(aa) > sz(pref)) pref = aa;
        }
      }

      if(sz(suf) == 0) suf = cc;
      else {
        int a = sz(suf) - 1, b = sz(cc) - 1;
        while(a >= 0 and b >= 0) {
          if(suf[a] != cc[b]) {
            at2 = true;
            break;
          }
          a--, b--;
        }

        if(!at2) {
          if(sz(cc) > sz(suf)) suf = cc;
        }
      }
    }    

    string ans;

    if(at2) ans = "*";
    else ans = pref + meio + suf;

    cout << "Case #" << tt++ << ": " << ans << endl;
  }

  return 0;
}