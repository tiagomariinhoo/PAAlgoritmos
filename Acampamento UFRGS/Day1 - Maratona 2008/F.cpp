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
// #define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n){
		if(!n) break;
		vi vec, vec2;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			vec2.pb(a);
		}

		vec.pb(vec2[sz(vec2)-1]);
		for(int i=0;i<sz(vec2);i++) vec.pb(vec2[i]);
		vec.pb(vec2[0]);

		int ans = 0;
		// if(n == 2){
			// if(vec[0] != vec[1]) cout << 2 << endl;
			// else cout << 0 << endl;
			// continue;
		// } else {
			for(int i=1;i<sz(vec)-1;i++){
				if(vec[i] > vec[i-1] and vec[i] > vec[i+1]) ans++;
				if(vec[i] < vec[i-1] and vec[i] < vec[i+1]) ans++;
			}
		// }
		cout << ans << endl;
	}


	return 0;
}