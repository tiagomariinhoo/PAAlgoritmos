#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
// #define MAXN (int)1e7 * 1.5
// #define MAXL 3000



int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while(1){
    cin >> n;
    if(!n) break;
    int aa = 0, bb = 0;
    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      if(!a) aa++;
      else bb++;
    }
  
    cout << "Mary won " << aa << " times and John won " << bb << " times" << endl;
  }    


   return 0; 
} 