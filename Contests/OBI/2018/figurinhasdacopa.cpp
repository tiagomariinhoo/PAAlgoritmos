#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 99999999
#define MAXL 20
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
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,c,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> c >> m;
	vi vec, vec2;
	for(int i=0;i<c;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	for(int i=0;i<m;i++){
		int a;
		cin >> a;
		vec2.pb(a);
	}

	for(int i=0;i<sz(vec2);i++){
		for(int j=0;j<sz(vec);j++){
			if(vec[j] == vec2[i]){
				vec[j] = -1;
			}
		}
	}

	int ans = 0;
	for(int i=0;i<sz(vec);i++){
		if(vec[i] != -1) ans++;
	}

	cout << ans << endl;

	return 0;
}