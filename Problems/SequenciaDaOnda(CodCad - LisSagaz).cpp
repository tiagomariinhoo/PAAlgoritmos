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
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
vi vec;
int ll[1000000], rr[1000000];
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}
	// set<int> a,b;
	// set<int>::iterator it, it2;
	vi vec2 = vec;
	reverse(vec2.begin(), vec2.end());

	// for(int i=0;i<sz(vec);i++) cout << vec[i] << " ";
	// 	cout << endl;
	// for(int i=0;i<sz(vec2);i++) cout << vec2[i] << " ";
	// 	cout << endl;
	
	int ans = 0;
	vi pilha, pilha2;
	for(int i=0;i<sz(vec);i++){
		vi ::iterator it = lower_bound(pilha.begin(), pilha.end(), vec[i]);
		vi ::iterator it2 = lower_bound(pilha2.begin(), pilha2.end(), vec2[i]);

		if(it2 == pilha2.end()) pilha2.pb(vec2[i]);
		else *it2 = vec2[i];

		if(it == pilha.end()) pilha.pb(vec[i]);
		else *it = vec[i];
		ll[i] = sz(pilha);
		rr[n - i - 1] = sz(pilha2);
		// ans = max(ans, (min(sz(pilha), sz(pilha2))*2) - 1);
		// cout << sz(pilha) << " - " << sz(pilha2) << endl;
	}

	for(int i=0;i<sz(vec);i++){
		ans = max(ans, (min(ll[i], rr[i])*2) - 1);
	}


	// cout << "Tam : " << sz(pilha) << endl;

	// for(int i=0;i<sz(vec);i++){
	// 	a.insert(vec[i]);
	// 	b.insert(vec2[i]);
	// 	it = a.upper_bound(vec[i]);
	// 	it2 = b.upper_bound(vec2[i]);

	// 	if(it != a.end()) a.erase(it);
	// 	if(it2 != b.end()) b.erase(it2);
	// 	ll[i] = sz(a);
	// 	rr[n - 1 - i] = sz(b);
	// }

	// for(int i=0;i<sz(vec);i++) 
	// 	ans = max(ans, (min(ll[i], rr[i])*2) - 1);

	// for(int i=0;i<sz(vec);i++) cout << ll[i] << " - " << rr[i] << endl;

	cout << ans << endl;

	return 0;
}