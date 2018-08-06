#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 999999999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

lli n,k,m,d;

/**
Math problem
Maximizar a primeira pessoa, didividr pelo numero de pessoas na fila + 1 (já que ele é o primeiro)
*/

int main(){
	ios_base::sync_with_stdio(false);


	cin >> n >> k >> m >> d;
	if(d == 1){
		cout << m << endl;
		return 0;
	}

	lli ans = 0;
	for(lli i=0;i<= d - 1;i++){
		lli x = (n / ((k * i) + 1));
		if(k * i > n) break;
		if(x > m) x = m;
		// cout << i << " - " << x << endl;
		// cout << (i + 1) * x << endl;
		ans = max(ans, x*(i+1));
	}

	cout << ans << endl;

	return 0;
}