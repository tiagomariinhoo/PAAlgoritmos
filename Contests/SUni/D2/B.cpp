#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353 
#define lli unsigned long long int
#define sz(a) int(a.size())
#define M_PI 3.1415
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int ans[1010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int sum = 0;
  for(int i=0;i<=180;i++){
    ans[sum] = 1;
    sum += 6;
  }

  int n;
  while(cin >> n){
    if(ans[n]) cout << "Y" << endl;
    else cout << "N" << endl;
  }


  return 0;
}