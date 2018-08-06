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

int k, j;
char vec[31][31];

double check(double x, double y, double xx, double yy){
	return (sqrt((x-xx)*(x-xx) + (y-yy)*(y-yy))) * (double)10;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while(n--){
		cin >> k >> j;
		int xx, yy;
		int x, y;
		string s;
		for(int i=0;i<j;i++){
			cin >> s;
			for(int jj=0;jj<sz(s);jj++){
				if(s[jj] == 'F') x = i, y = jj;
				else if(s[jj] == 'J') xx = i, yy = jj;
			}
			// for(int jj=0;jj<j;jj++){
			// 	cin >> vec[i][jj];
			// 	if(vec[i][jj] == 'F') x = i, y = jj;
			// 	if(vec[i][jj] == 'J') xx = i, yy = jj;
			// }
		}	

		int aa = check(x, y, xx, yy);
		int ans = (k) / (pow(0.99, aa));

		cout << ans << " " << "dBs" << endl;
	}

}
