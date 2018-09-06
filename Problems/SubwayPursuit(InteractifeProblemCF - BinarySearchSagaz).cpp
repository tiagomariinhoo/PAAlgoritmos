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
#define MAXN 500001

lli n, k, c;
string s;

void solve(lli l, lli r){
	if(l > r) return ;
	c++;
	if(c >= 4501) exit(0);

	lli mini = max(1LL, l-k), maxi = min(n, r+k);
	if(maxi - mini <= 40){
			lli atual = rand()%(maxi - mini + 1) + mini;
			// printf("%lld %lld\n", atual, atual);
			cout << atual << " " << atual << endl;
			cin >> s;
			if(s == "Yes") exit(0);
			else solve( max(mini-k, 1LL) , min(maxi+k, n) );
	} else {
		lli mid = (mini + maxi)/2;
		// printf("%lld %lld\n", mini, mid);
		cout << mini << " " << mid << endl;
		cin >> s;
		if(s == "Yes") solve(mini, mid);
		else solve(mid+1, maxi);
	}
}

int main(){
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  cin >> n >> k;
  lli l = 1, r = n;
  lli l2 = 1, r2 = n;
  srand(time(NULL));

  while(1)
  solve(l, r);


  return 0;
}