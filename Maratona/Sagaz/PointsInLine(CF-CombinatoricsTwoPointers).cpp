#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF 191919
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vi vec;

// n * (n-1) / 2

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}
	if(sz(vec) < 3){
		cout << 0 << endl;
		return 0;
	} 

	int a = 0,b = 2;
	lli ans = 0;
	while(a < sz(vec)){
		while(b < sz(vec)){
			if(abs(vec[b] - vec[a]) <= m and b >= a + 2){
				lli tam = b - a;
				// cout << "Tam : " << tam << endl;
				// cout << (tam*(tam-1))/2 << endl;
				ans += (tam * (tam - 1))/2;
			} else if(abs(vec[b] - vec[a]) > m) break;
			b++;
		}
		a++;
	}

	cout << ans << endl;

	return 0;
}