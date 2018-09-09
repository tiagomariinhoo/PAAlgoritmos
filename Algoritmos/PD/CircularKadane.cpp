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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while(cin >> n){
  	n = (n*10);
  	vector<lli> vec;
  	for(int i=0;i<n;i++){
  		lli a;
  		cin >> a;
  		vec.pb(a);
  	}

  	for(int i=0;i<n;i++) vec.pb(vec[i]);

		lli ans = 0, sum = 0;
		for(int i=0;i<n;i++){
			sum = max(0LL, sum + vec[i]);
			ans = max(ans, sum);
		}  		
		lli sum2 = 0;
		for(int i=0;i<n;i++){
			sum2 += vec[i];
			vec[i] = -vec[i];
		}
		lli ans2 = 0;
		sum = 0;
		for(int i=0;i<n;i++){
			sum = max(0LL, sum + vec[i]);
			ans2 = max(ans2, sum);
		}

		sum2 += ans2;

		cout << max(ans, sum2) << endl;
  }

  return 0;
}