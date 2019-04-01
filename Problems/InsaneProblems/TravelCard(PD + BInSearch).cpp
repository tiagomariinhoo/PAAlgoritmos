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

int n;
vector<lli> vec;
lli pd[MAXN];
lli sum[MAXN];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vec.push_back(a);
  }

  pd[0] = 20;
  for(int i=1;i<n;i++){
    pd[i] = min({
      pd[i-1] + 20,
      pd[lower_bound(vec.begin(), vec.end(), vec[i] - 89) - vec.begin() - 1] + 50,
      pd[lower_bound(vec.begin(), vec.end(), vec[i] - 1439) - vec.begin() - 1] + 120
    });
  }

  cout << pd[0] << endl;
  for(int i=1;i<n;i++) cout << pd[i] - pd[i-1] << endl;  

  return 0;
}