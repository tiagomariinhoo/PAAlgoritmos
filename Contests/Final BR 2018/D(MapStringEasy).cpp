#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
// typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100010
#define MAXL 20
#define MOD2 998244353

int n;
set<string> ans;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    string s;
    cin >> s;

    string aux = "";
    bool at = false, at2 = false;
    for(int j=0;j<sz(s);j++){
      if(s[j] == '@' and !at2) at = false, at2 = true;
      if(s[j] == '.' and !at2) continue;
      else if(s[j] == '+' and !at2) at = true;
      if(at) continue;
      aux += s[j];
    }
    ans.insert(aux);
  }


  cout << sz(ans) << endl;

  return 0;
} 