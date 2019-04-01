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

lli n;
lli vec[1010101];
lli pre[1010101];
int vis[1010101];

/*
  Explicação: https://codeforces.com/blog/entry/65994?#comment-500104

  Separar os termos e soma para achar o termo a1, depois simula
  E vê se dá alguma resposta
*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for(int i=1;i<=n-1;i++) cin >> vec[i];

  lli sum = 0;
  for(int i=1;i<=n-1;i++) pre[i] += pre[i-1] + vec[i], sum += pre[i];

  lli a = (sum - (n*(n+1)/2))/n;
  a *= -1;
  if(a < 1 or a > n){
    cout << -1 << endl;
    return 0;
  }

  vector<lli> ans;
  ans.push_back(a);
  vis[a] = 1;
  for(int i=1;i<=n-1;i++){
    a += vec[i];
    if(a < 1 or a > n or vis[a]){
      cout << -1 << endl;
      return 0;
    }
    vis[a] = 1;
    ans.push_back(a);
  }

  for(auto i : ans) cout << i << " ";
  cout << endl;

  return 0;
}