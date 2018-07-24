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
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
// #define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	while(cin >> k){
		if(!k) break;
		int n,m;
		cin >> n >> m;
		for(int i=0;i<k;i++){
			int a, b;
			cin >> a >> b;
			// cout << n << " - " << m << endl;
			// cout << a << " -- " << b << endl;
			if(a == n or b == m) cout << "divisa" << endl;
			else if(a > n  and b > m) cout << "NE" << endl;
			else if(a < n and b > m) cout << "NO" << endl;
			else if(a > n and b < m) cout << "SE" << endl;
			else if(a < n and b < m) cout << "SO" << endl;
		}


	}

	return 0;
}