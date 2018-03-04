#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
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
typedef pair<lli, lli> iil;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

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

	lli n;
		cin >> n;
	lli ans = n;
	lli tam = n;
	if(n > 10) tam = n - 10;
	else tam = 1;
	for(lli i = tam; i<= n; i++){
		for(lli j = tam; j <=n; j++){
			for(lli k = tam; k <= n; k++){
				lli aux = lcm(i, lcm(j, k));
				// cout << "Aux : " << aux << endl;
				ans = max(ans, aux);
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}