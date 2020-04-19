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

int n=4;
int dist[10][10] = 
{
  {0, 20, 42, 25},
  {20, 0, 30, 34},
  {42, 30, 0, 10},
  {25, 34, 10, 0}
};

//GetPath tsp https://codeforces.com/blog/entry/47782

int tsp(int mask, int pos){
  if(mask == ((1 << n) - 1)) return dist[pos][0];

  int ans = INT_MAX;
  for(int i=0;i<n;i++){
   if((mask&(1 << i)) == 0){
    int aux = dist[pos][i] +  tsp(mask|(1<<i), i);
    ans = min(ans, aux);
   } 
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cout << tsp(1, 0) << endl;

  return 0;
} 