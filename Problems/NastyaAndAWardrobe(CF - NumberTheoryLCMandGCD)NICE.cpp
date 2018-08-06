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

int l, r, x, y;

lli gcd(lli a, lli b){
	while(1){
		if(a == 0) return b;
		b%=a;
		if(b == 0) return a;
		a %= b;
	}
}

lli lcm(lli a, lli b){
	lli temp = gcd(a,b);
	return temp ? (a / temp*b) : 0;
}
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> l >> r >> x >> y;

	lli ans = 0;

	// cout << gcd(15,10) << " - " << lcm(15, 10) << endl;

	// int xx = 16, yy = 16;
	// for(int i=1;i<=100;i++){

	// 	if(yy/i == 0) break;
	// 	if(yy%i != 0) continue;
	// 	cout << "I : " << i << endl;
	// 	cout << xx*i << " - " << yy/i << endl;
	// 	cout << "Res : ";
	// 	cout << (xx*i)*(yy/i) << endl;
	// }

	for(int i=1;i<=100000;i++){
		lli aa = x*i, bb = y/i;
		if(y%i!=0) continue;
		// cout << aa << " - " << bb << endl;
		if(aa >= l and aa <= r and bb >= l and bb <= r and lcm(aa, bb) == y and gcd(aa, bb) == x and aa <= bb){
			if(aa != bb)
			ans+=2;
			else ans++;
		} else if(aa > bb) break;
	}

	cout << ans << endl;

	return 0;
}