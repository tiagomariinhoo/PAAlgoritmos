#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 

map<int, set<pair<lli, lli>> > pos[600001];

void guarda(string s){

  lli p = 31;
  lli m = MOD;
  int n = sz(s);
  vector<lli> h(sz(s)+1, 0), p_pow(sz(s)+1);
  p_pow[0] = 1;

  for(int i=1;i<sz(s);i++)
    p_pow[i] = (p_pow[i-1] * p)%m;
  for(int i=0;i<sz(s);i++)
    h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i])%m;

  //Pega a substring em O(1)
  /*
  Atual: String[0..i-1]
  Atual2: String[i+1, n-1]
  */ 
  for(int i=1;i<=n;i++){
    lli atual = (h[i-1] - h[0] + m)%m;
    atual = (atual * p_pow[n-1])%m;
    
    lli atual2 = (h[n] - h[i] + m)%m;
    atual2 = (atual2 * p_pow[n-i-1])%m;
    // cout << atual << " - " << s[i-1] << " - " << atual2 << endl;
    pos[n][s[i-1]-'a'].insert({atual, atual2});
  }
}

bool tenta(string s){
  lli p = 31;
  lli n = sz(s);
  lli m = MOD;
  vector<lli> h(n+1, 0), p_pow(n+1);
  p_pow[0] = 1;

  for(int i=1;i<sz(s);i++) p_pow[i] = (p_pow[i-1]*p)%m;
  for(int i=0;i<sz(s);i++){
    h[i+1] = (h[i] + (s[i] - 'a' + 1)*p_pow[i])%m;
  }

  for(int i=1;i<=n;i++){
    lli atual = (h[i-1] - h[0] + m)%m;
    atual = (atual * p_pow[n-1])%m;
    lli atual2 = (h[n] - h[i] + m)%m;
    atual2 = (atual2 * p_pow[n-i-1])%m;

    for(int j='a';j<='c';j++){
      if(j == s[i-1]) continue;
      if(pos[n][j-'a'].find({atual, atual2}) != pos[n][j-'a'].end()) return true;
    }

  }

  return false;
}

int n, q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;

  for(int i=0;i<n;i++){
    string a;
    cin >> a;
    guarda(a);
  }

  for(int i=0;i<q;i++){
    string a;
    cin >> a;
    if(tenta(a)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}