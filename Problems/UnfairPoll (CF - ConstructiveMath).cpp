#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX INT_MAX
#define MAXL LLONG_MAX
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

unsigned long long int n,m,k,x,y;
lli ans[100][100];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k >> x >> y;

	lli T = (n*m) + (n-2)*m;
	if(n == 1) T = m;
	lli aux = k/T;
	lli resto = k%T;

	// cout << T << " - " << aux << " - " << resto << endl;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!i or i == n-1){
				ans[i][j] = aux;
			} else {
				ans[i][j] = aux*2;
			}
		}
	}

	if(resto){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(resto) ans[i][j]++, resto--;
			}
		}
	}

	if(resto){
		for(int i = n-2; i>=0;i--){
			for(int j=0;j<m;j++){
				if(resto) ans[i][j]++ ,resto--;
			}
		}
	}

	lli maxi = 0, mini = LLONG_MAX, serge;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			maxi = max(ans[i][j], maxi);
			mini = min(ans[i][j], mini);
			if(i+1 == x and j + 1 == y) serge = ans[i][j];
		}
	}

	cout << maxi << " " << mini << " " << serge << endl;

	return 0;
}