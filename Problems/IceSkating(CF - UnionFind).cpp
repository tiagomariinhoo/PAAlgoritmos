#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF 999998
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
//\n

int n;
vector<ii> l[1010], r[1010], vec;
int pai[1010], pai2[1010];
int peso[1010], peso2[1010];

int find(int x, int at){
	if(at == 1){
		if(pai[x] == x) return x;
		return pai[x] = find(pai[x], at);
	} else {
		if(pai2[x] == x) return x;
		return pai2[x] = find(pai2[x], at);
	}
}

void join(int x, int y, int at){
	
	if(at == 1){
			x = find(x, at);
			y = find(y, at);

			if(x == y) return ;
			if(peso[x] < peso[y]){
				pai[x] = y;
			} else if(peso[x] > peso[y]){
				pai[y] = x;
			} else {
				pai[x] = y;
				peso[y]++;
			}
	} else {
		x = find(x, at);
		y = find(y, at);

		if(x == y) return ;
		if(peso2[x] < peso2[y]){
			pai2[x] = y;
		} else if(peso2[x] > peso2[y]){
			pai2[y] = x;
		} else {
			pai2[x] = y;
			peso2[y]++;
		}
	}
}

bool proc(int x, int y, int xx, int yy){
	// cout << x << " - " << y << " 1-1 " << xx << " - " << yy << endl << endl;
	for(int i=0;i<sz(l[x]);i++){
		for(int j=0;j<sz(l[xx]);j++){
			int a = find(l[x][i].F, 1);
			int b = find(l[xx][j].F, 1);
			int c = find(l[x][i].S , 2);
			int d = find(l[xx][j].S, 2);
			// cout << l[x][i].F << " - " << l[x][i].S << " __ " << l[xx][j].F << " - " << l[xx][j].S << endl;
			// cout << a << " - " << b << " - " << c << " - " << d << endl;
			
			if(a == b or c == d) return true;
		}
	}
	// cout << " ---- " << endl;
	for(int i=0;i<sz(r[y]);i++){
		for(int j=0;j<sz(r[yy]);j++){
			int a = find(r[y][i].F, 1);
			int b = find(r[yy][j].F, 1);
			int c = find(r[y][i].S, 2);
			int d = find(r[yy][j].S, 2);
			// cout << r[y][i].F << " - " << r[y][i].S << " __ " << r[yy][j].F << " - " << r[yy][j].S << endl;
			// cout << a << " - " << b << " - " << c << " - " << d << endl;
			if(a == b or c == d) return true;
		}
	}
	// cout << 1121 << endl;
	return false;
}

int main(){
	cin >> n;
	for(int i=1;i<=1009;i++) pai[i] = i, pai2[i] = i;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		vec.pb({a,b});
		l[a].pb({a,b});
		r[b].pb({a,b});
	}

	int ans = 0;

	for(int i=0;i<sz(vec);i++){
		for(int j=i+1;j<sz(vec);j++){
			int a = vec[i].F, b = vec[i].S;
			int c = vec[j].F, d = vec[j].S;
			if(a == c or b == d){
				join(a, c, 1);
				join(b, d, 2);
			}
		}
	}

	for(int i=0;i<sz(vec);i++){
		for(int j=i+1;j<sz(vec);j++){
			if(!proc(vec[i].F, vec[i].S, vec[j].F, vec[j].S)){
				ans++;
				join(vec[i].F, vec[j].F, 1);
				join(vec[i].S, vec[j].S, 2);
			}
		}
	}


	cout << ans << endl;

	return 0;
}