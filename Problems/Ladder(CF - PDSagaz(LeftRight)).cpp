#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vi vec;
int l[100005], r[100005];

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	l[sz(vec)-1] = 0;
	r[0] = 0;
	for(int i=1;i<sz(vec);i++){
		if(vec[i] <= vec[i-1]) r[i] = r[i-1] + 1;
		else r[i] = 0;
	}

	for(int i=sz(vec)-2;i>=0;i--){
		if(vec[i] <= vec[i+1]) l[i] = l[i+1] + 1; 
		else l[i] = 0;
	}

	// for(int i=0;i<sz(vec);i++) cout << l[i] << " ";
	// 	cout << endl;
	// for(int i=0;i<sz(vec);i++) cout << r[i] << " ";
	// 	cout << endl;

	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		a--, b--;
		if(l[a] + r[b] + 1 >= b - a + 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}


	return 0;
}