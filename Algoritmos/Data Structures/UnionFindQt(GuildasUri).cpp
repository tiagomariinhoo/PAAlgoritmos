#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (500000000)
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
int pai[100010];
int peso[100010];
int vec[100010];
int qt[100010];
int ans = 0;

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

int test(int x, int y){
	int aa = vec[find(pai[x])];
	int bb = vec[find(pai[y])];
	// cout << aa << " - " << bb << endl;

	// cout << "X : " << x << " - " << "Y : " << y << endl;
	if(aa > bb){
		if(find(1) == find(x)) return 1;
	} else if(aa < bb){
		if((find(1)) == find(y)) return 1;
	}
	return 0;
}

void join(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return ;

	if(peso[x] < peso[y]){
		pai[x] = y;
		vec[y] += vec[x];
	} else if(peso[x] > peso[y]){
		pai[y] = x;
		vec[x] += vec[y];
	} else {
		pai[x] = y;
		peso[y]++;
		vec[y] += vec[x];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		cin >> n >> m;
		ans = 0;
		if(n == 0 and m == 0) break;
		for(int i=1;i<=n;i++) cin >> vec[i];
		memset(peso, 0, sizeof peso);
		for(int i=1;i<=n;i++) pai[i] = i;
		for(int i=0;i<m;i++){
			int a,b,c;
			cin >> a >> b >> c;
			if(a == 1){
				join(b,c);
			} else {
				ans += test(b,c);
			}
		}	
		cout << ans << endl;
	}


	return 0;
}