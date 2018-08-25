#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

string s;
int z[1000001];
int n;

void zAlgo(){
  int l = 0, r = 0;
  for(int i=1;i<n;i++){
    if(l > r){
      l = r = i;
      while(r < n and s[r - l] == s[r]) r++;
      z[i] = r - l, r--;
    } else {
      int k = i - l;
      if(z[k] < r - i + 1) z[i] = z[k];
      else {
        l = i;
        while(r < n and s[r - l] == s[r]) r++;
        z[i] = r - l;
        r--;
      }
    }
  }
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> s;

  s += s;
  n = sz(s);

  zAlgo();

  for(int i=1;i<n;i++){
    int atual = z[i];

    if(i + atual >= n) continue;

    if(s[atual + i] < s[i]){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}