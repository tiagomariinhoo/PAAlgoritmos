#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 100005
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
typedef pair<lli,lli> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
lli vec[150505];
map<lli, set<lli> > qt;
vector<ii> ans;
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> vec[i];
		qt[vec[i]].insert(i);
	}

	for(auto i : qt){
		if(sz(i.S) >= 2){
			lli tam = sz(i.S);
			lli rr = 0;
			vector<lli> aa;

			for(auto j : i.S){
				aa.pb(j);
			}
			for(int j=0;j<sz(aa) - 1;j++){
				qt[i.F*2].insert(aa[j+1]);
				j++;
			}

			if(tam%2 != 0) ans.pb({aa[sz(aa) - 1], i.F});

		} else {
			for (auto j : i.S) ans.pb({j, i.F});
		}
	}
	sort(ans.begin(), ans.end());
	cout << sz(ans) << endl;
	for(int i=0;i<sz(ans);i++) cout << ans[i].S << " ";
		cout << endl;


	return 0;
}