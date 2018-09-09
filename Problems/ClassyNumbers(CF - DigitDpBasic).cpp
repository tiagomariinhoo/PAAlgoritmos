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

int t;
string s;
lli pd[20][2][4];

lli solve(int obj, int can, int qt){
	if(qt > 3) return 0;
	if(obj == sz(s)) return 1;
	lli &ans = pd[obj][can][qt];
	if(ans != -1) return ans;

	int atual = can ? s[obj] - '0' : 9;

	lli a = 0;
	a += solve(obj+1, 0 == s[obj] - '0' ? can : 0, qt);
	for(int i=1;i<=atual;i++)
		a += solve(obj+1, i == s[obj] - '0' ? can : 0, qt+1);

	return ans = a;
}

int check(string a){
	int aa = 0;
	for(int i=0;i<sz(a);i++) if(a[i] - '0' != 0) aa++;
	return aa <= 3;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  for(int i=0;i<t;i++){
  	string a, b;
  	cin >> a >> b;
  	s = a;
  	memset(pd, -1, sizeof pd);
  	lli atual = solve(0, 1, 0);
  	s = b;
  	memset(pd, -1, sizeof pd);
  	lli atual2 = solve(0, 1, 0);
  	cout << atual2 - atual + check(a) << endl;
  }

  return 0;
}