#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
// int ddx[] = {1, 0};

vi vec;
int n, c;
int ans = 0;

//Test difs with BS

bool check(int dif){
	int a = 0, cc = c-1;
	for(int i=1;i<sz(vec);i++){
		if(!cc) break;
		if(vec[i] - vec[a] >= dif){
			cc--;
			a = i;
		}
	}
	if(cc) return false;
	ans = max(ans, dif);
	return true;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		cin >> n >> c;
		vec.clear();

		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			vec.pb(a);
		}

		sort(vec.begin(), vec.end());

		int com = 0, fim = vec[sz(vec)-1] - vec[0];

		while(com <= fim){
			int mid = (com + fim) >> 1;
			if(check(mid)) com = mid + 1;
			else fim = mid - 1;
		}

		cout << ans << endl;
		ans = 0;

	}

	return 0;
}