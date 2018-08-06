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
#define MOD 1e9 + 9
#define MOD2 1e9 + 7
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


		int pd[6001][6001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){

		string s, ss;	
		cin >> s;
		ss = s;
		reverse(s.begin(), s.end());

		int n = sz(s);
		memset(pd, 0, sizeof pd);
		for(int i=0;i<n;i++) pd[0][i] = pd[i][0] = 0;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
					int comp = (s[i-1] == ss[j-1]);
					pd[i][j] = 0;
					pd[i][j] = max(
						{ pd[i-1][j], pd[i][j-1], pd[i-1][j-1] + comp }
					)	;
				}
			}

			// for(int i=0;i<=n;i++){
			// 	for(int j=0;j<=n;j++) cout << pd[i][j] << " ";
			// 		cout << endl;
			// }
		cout << sz(s) - pd[n][n] << endl;
	}


	return 0;
}