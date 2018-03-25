#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF 191919
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
int vec[101010];

lli bs(int x){
	int com = x;
	int fim = n-1;
	int ans = -1;

	while(com < fim){
		int mid = (com + fim + 1) >> 1;

		if(abs(vec[mid] - vec[x]) <= m) ans = mid, com = mid;
		else if(abs(vec[mid] - vec[x]) > m) fim = mid - 1;
	}

	if(ans == -1 or abs(x - ans) < 2) return 0;
	lli tam = ans - x;
	lli aux = (tam * (tam - 1)) / 2;
	return aux;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> vec[i];

	lli ans = 0;
	for(int i=0;i<n;i++){
		ans += bs(i);
	}

	cout << ans << endl;

	return 0;
}