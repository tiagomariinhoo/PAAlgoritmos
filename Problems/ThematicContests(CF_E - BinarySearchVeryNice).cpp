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
vector<lli> vec;
map<int, int> qt;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i=0;i<n;i++){
    lli a;
    cin >> a;
    qt[a]++;
  }

  for(auto i : qt) vec.pb(i.S);

  sort(vec.begin(), vec.end());

  int ans = 0;


  // for(auto i : vec) cout << i << " ";
    // cout << endl;

  for(int i=1;i<=2*1e5+1;i++){
    int com = 0, fim = sz(vec) - 1;
    int atual = i, sum = 0;
    int pos = -1;
    while(1){
    bool at = false;
    com = pos + 1, fim = sz(vec) - 1;
    // cout << i << " - " << atual << endl;
      while(com <= fim){ 
        int mid = (com + fim) >> 1;
        if(vec[mid] >= atual){
          pos = mid;
          // cout << pos << " - " << mid << endl;
          fim = mid - 1;
          at = true;
        } else com = mid + 1;
      }
      if(!at) break;
    // cout << "pos : " << pos + 1 << endl;
      sum += atual;
      // cout << "sum : " << sum << endl;
      atual *= 2;
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;

  return 0;
} 