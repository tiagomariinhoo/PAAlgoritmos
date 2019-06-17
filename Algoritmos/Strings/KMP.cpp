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

int t;
string txt, pat;
int lps[MAXN];

void compLps(){
  int i = 1, len = 0;
  while(i < sz(pat)){
    if(pat[len] == pat[i]){
      lps[i] = ++len;
      i++;
    } else {
      if(len > 0) len = lps[len - 1];
      else i++;
    }
  }
}

void kmp(){
  vector<int> ans;
  int i = 0, j = 0;

  while(i < sz(txt)){
    if(txt[i] == pat[j]){
      i++,j++;
    } else {
      if(j > 0) j = lps[j-1];
      else i++;
    }

    if(j == sz(pat)){
      ans.push_back(i-j+1);
      j = lps[j-1];
    }
  }
  if(sz(ans) > 0){
    cout << sz(ans) << endl;
    for(auto i : ans) cout << i << " ";
    cout << endl << endl;
  } else cout << "Not Found" << endl << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while(t--){

    cin >> txt >> pat;
    memset(lps, 0, sizeof lps);
    compLps();
    kmp();
  }

  return 0;
}