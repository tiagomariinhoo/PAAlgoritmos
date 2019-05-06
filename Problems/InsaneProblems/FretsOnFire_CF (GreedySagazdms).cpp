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
lli anss[MAXN];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    cin >> vec[i];
  }


  sort(vec, vec + n);

  for(int i=0;i<n-1;i++){
    vec[i] = (vec[i+1] - vec[i]);
  }

  sort(vec, vec+n-1);

  lli pre[MAXN];

  pre[0] = 0;
  for(int i=0;i<n-1;i++) pre[i+1] = pre[i] + vec[i];

  int q;
  cin >> q;
  for(int i=0;i<q;i++){
    lli a, b;
    cin >> a >> b;
    lli w = b - a + 1;
    lli idx = lower_bound(vec, vec+n-1, w) - vec;
    cout << (n - idx) * w + pre[idx] << " ";
  } cout << endl;

  return 0;
}