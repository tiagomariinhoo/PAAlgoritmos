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
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
#define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};

unsigned long long int l, r;

void toBinary(unsigned long long int n){
	vi ans;
	while(n){
		if(n&1) ans.pb(1);
		else ans.pb(0);
		n >>= 1;
	}
	reverse(ans.begin(), ans.end());
	for(int i=0;i<sz(ans);i++) cout << ans[i] << " ";
		cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> r;

	// for(int i=1;i<=30;i++){
	// 	cout << i << " : ";
	// 	toBinary(i);
	// }


	int i = 0, p = 0;
	while(l | r){
		i++;
		if(l ^ r) p = i;
		l >>= 1; r >>= 1;
	}
	cout << (1ll << p) - 1 << endl;
	return 0;
}