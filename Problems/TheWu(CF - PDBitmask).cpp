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
#define lli long long int
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

int n, m, q;
vi vec;
int pd[5001][120];
unordered_map<int, int> qt;
int conv(string x){

  int atual = 0;
  int xx = 0;
  for(int i=sz(x)-1;i>=0;i--){
    atual += (x[i] - '0') * (pow(2,xx));
    xx++;
  }

	return atual;  
}

int solve(string a, int b){
	if(b > 100) return 0;

	int atual = conv(a);
	if(pd[atual][b]) return pd[atual][b];
	int sum = 0;
	for(auto i : qt){
		int aux = i.F;
		for(int j=0;j<=n-1;j++){
			if((aux & (1 << j)) == (atual & (1 << j))){
				// cout << aux << " _ " << atual << " _ " << j << endl;
				sum += vec[sz(vec) - j - 1];
			}
		}
		// cout << atual << " - " << aux << " - " << sum << endl;
		// cout << i.S << endl;
		if(sum <= 100) pd[atual][sum]+=i.S;
		sum = 0;
	}

	for(int i=1;i<=100;i++){
		pd[atual][i] += pd[atual][i-1];
	}
	return pd[atual][b];
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> q;
  for(int i=0;i<n;i++){
  	int a;
  	cin >> a;
  	vec.pb(a);
  }

  // int aa = sz(vec);
  // for(int i=0;i<12-aa;i++) vec.pb(0);

  for(int i=0;i<m;i++){
  	string a;
  	cin >> a;
  	qt[conv(a)]++;
  }

  for(int i=0;i<q;i++){
  	string a;
  	int b;
  	cin >> a >> b;
  	cout << solve(a, b) << endl;
  }

  return 0;
}