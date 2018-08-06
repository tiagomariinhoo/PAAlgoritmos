#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF (1<<30)
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
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

lli n,m;
string::size_type sz = 0;

lli solve(lli x){
	std::string aux = to_string(x);
	// cout << "Aux : " << aux << endl;
	for(int i=aux.size()-1;i>=0;i--) aux+=aux[i];

	long long ans = stoll(aux, &sz, 0);
	// cout << ans << endl;
	return ans;
}

int main(){
	cin >> n >> m;
	vector<lli> ans;

	for(lli i=1;i<=n;i++){
		ans.pb(solve(i));
	}

	lli sum = 0;
	for(int i=0;i<sz(ans);i++) sum+=(ans[i]);

	cout << sum%m << endl;

	return 0;
}