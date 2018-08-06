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

int n;
vector<pair<string, ii>> vec;
map<lli, lli> qt;
int vis[300001];
int vis2[300001];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		int a = 0, b = 0;
		bool at = false;
		bool at2 = false;

		for(int j=0;j<sz(s);j++){
			if(s[j] == '(') a++;
			else {
				if(a) a--;
				else b++;
			}
		}

		vis[i] = a - b;
		qt[vis[i]]++;
		if(a > 0 and b > 0) vis2[i] = -1, qt[vis[i]]--;

		vec.pb({s,{a,b}});
	}

	lli ans = qt[0];
	for(int i=0;i<sz(vec);i++){
		// cout << vec[i].F << " - " << vis2[i] << endl;
		// cout << vis[i] << endl;
		if(vis2[i] == -1) continue;
		if(vis[i] == 0){
			// continue;
			ans += qt[vis[i]] - 1;
			// qt[vis[i]]--;
		} else if(vis[i] < 0){
			// ans += qt[abs(vis[i])];
			// qt[vis[i]]--;
		} else {
			ans += qt[vis[i]*-1];
			// qt[vis[i]]--;
		}
		// cout << vec[i].F << " - " << ans << endl;
	}

	cout << ans << endl;

	return 0;
}
