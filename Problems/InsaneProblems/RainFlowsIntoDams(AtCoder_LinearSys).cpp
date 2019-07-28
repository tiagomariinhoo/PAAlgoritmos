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

/*
Resolve o sistema de eq linear
5
3 8 7 5 5

6 16 14 10 10
x1 + x2 = 6
x2 + x3 = 16
x3 + x4 = 14
x4 + x5 = 10
x5 + x1 = 10

6 - 16 + 14 - 10 + 10

*/

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    lli a;
    cin >> a;
    vec.push_back(a*2);
  }

  lli sum = vec[0];
  lli x1 = 0;

  bool at = false;
  for(int i=1;i<sz(vec);i++){
    if(!at){
      sum -= (vec[i]);
      at = true;
    } else {
      sum += vec[i];
      at = false;
    }
  }

  lli atual = sum/2;
  vector<lli> ans;
  ans.push_back(sum/2);
  for(int i=0;i<sz(vec) - 1;i++){
    ans.push_back(vec[i] - atual);
    atual = vec[i] - atual;
  }

  for(auto i : ans) cout << i << " ";
  cout << endl;

  return 0;
}