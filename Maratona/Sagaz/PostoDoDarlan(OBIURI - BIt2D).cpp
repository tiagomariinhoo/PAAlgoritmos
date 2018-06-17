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
typedef vector<int> vi;
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

int n,m;
vector<string> vec;
int l;
lli bit[1001][1001];

lli sum(int x, int y){
	int ans = 0;
	for(int i=x;i>0;i-=i&-i)
		for(int j=y;j>0;j-=j&-j) ans += bit[i][j];

	return ans;
}

void update(int x, int y, int d){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j) bit[i][j] += d;
}

bool can(int x, int y, int xx, int yy){
	int a = 0, b = 0;
	for(int i = x;i < xx;i++){
		for(int j = y;j < yy;j++){
			if(vec[i][j] == 'C') a++;
			else b++;

			if(a and b) return true;
		}

	}
	return false;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;

		for(int j=0;j<sz(s);j++){
			if(s[j] == 'C') update(i+1, j+1, 25);
			else update(i+1, j+1, 12);
		}

		vec.pb(s);
	}

	cin >> l;
	lli ans = 0;

	for(int i=0;i < sz(vec)- l + 1;i++){
		for(int j=0;j <= sz(vec[i]) - l; j++){
			// cout << i << " " << j << endl;
			if(can(i, j , i + l, j+l)){
				// lli soma = (sum(i + l, j + l) - sum(i,j));
				lli soma = sum(i, j) - sum(i + l, j) - sum(i, j + l) + sum(i + l, j + l); 
				// cout << i + l << " - " << j + l << " -- " << i << " - " << j<< endl;
				// cout << "Soma : " << soma << endl;
				// cout << i << " _ " << j << " _ " << "Soma : " << soma << endl;
				ans = max(ans, soma);
				// cout << 1 << endl;
			}
		}
	}

	if(!ans) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
