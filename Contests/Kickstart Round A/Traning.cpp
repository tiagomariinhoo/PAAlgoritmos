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

int t;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  int xd = 1;
  while(t--){
    int n, p;
    cin >> n >> p;
    vector<int> vec;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      vec.push_back(a);
    }
    sort(vec.begin(), vec.end());

    int a = 0, b = p-1;
    int atual = vec[b] - vec[a];
    int aa = 0, bb = p-1;
    while(a < sz(vec) - p + 1){
      while(b < sz(vec) and b < a + p){
        if(vec[b] - vec[a] < atual) aa = a, bb = b, atual = vec[bb] - vec[aa];
        b++;
      } 
      a++;
    }

    lli ans = 0;
    for(int i=aa;i<=bb-1;i++){
      ans += vec[bb] - vec[i];
    }
    cout << "Case #" << xd << ": " << ans << endl;
    xd++;

  }




  return 0;
}