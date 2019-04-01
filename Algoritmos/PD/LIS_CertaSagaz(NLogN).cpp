#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 10)
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
int a[MAXN], b[MAXN], f[MAXN];

void printLIS(int ans){
  int require = ans;
  vector<int> T;
  for(int i=n;i>=1;i--){
    if(f[i] == require){
      T.push_back(a[i]);
      require--;
    }
  }
  reverse(T.begin(), T.end());
  for(auto i : T) cout << i << " ";
  cout << endl;
}

void LIS(){
  int ans = 0;
  for(int i=1;i<=n;i++){
    f[i] = lower_bound(b+1, b+ans+1, a[i]) - b;
    ans = max(ans, f[i]);
    b[f[i]] = a[i];
  }

  cout << ans << endl;
  printLIS(ans);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++){
    cin >> a[i];
  }

  LIS();


  return 0;
}