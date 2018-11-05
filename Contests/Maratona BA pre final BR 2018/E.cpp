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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20
#define MOD2 998244353

string s;

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  int a = 0;
  for(int i=0;i<sz(s);i++){
  	if(s[i] == '1') a++;
  }

  if(a%2==0) cout << "YES" << endl;
  else cout << "NO" << endl;

  // int see = 0, sum2 = 0;
  // bool at = false;
  // int sum = 0;
  // for(int i=0;i<sz(s)-1;i++) sum ^= (s[i] - '0');

  // for(int i=sz(s)-1;i>=0;i--){
  // 	if(!i){
  // 		if(sum2 != s[i]-'0') at = true;
  // 		break;
  // 	}

  // 	if(s[i] == '0'){
  // 		if(sum2 != sum) at = true;
  // 	} else {
  // 		if(see == sum) at = true;
  // 		sum2 ^= (s[i] - '0');
  // 	}
  // 	// cout << i << " - " << at << endl;
  // 	sum ^= (s[i-1] - '0');
  // }

  // // sum  =0;
  // // for(int i=1;i<sz(s);i++){
  // // 	sum ^= s[i] - '0';
  // // }
  // // if(sum != s[0] - '0') at = true;

  // if(!at) cout << "YES" << endl;
  // else cout << "NO" << endl;

  return 0;
}