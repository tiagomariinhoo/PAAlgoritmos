#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(3*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
lli vec[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++) cin >> vec[i];

  lli ans = 0;
  lli c = 0;
  for(int i=0;i<n;i++){
    
    lli atual = vec[i]/2;
    ans += min(c, atual);
    vec[i] -= min(c*2, 2*atual);
    c -= min(c, atual);
    ans += (vec[i]/3);
    vec[i]%=3;
    c += (vec[i]);

  // cout << i << " - " << ans << endl;
  // cout << c << endl;
  // cout << vec[i] << endl << endl;
  }

  cout << ans << endl;

  return 0;
}
