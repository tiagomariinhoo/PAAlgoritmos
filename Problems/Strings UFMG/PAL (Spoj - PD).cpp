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
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
// int ddx[] = {1, 0};
// int ddy[] = {1, 1};

int pd[2001][2001];
int c[2001];
string s;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	while(1){
		int n;
		 cin >> n;
		 if(n == 0) break;
		 cin >> s;
		 if(t!=1) cout << endl;
		 memset(pd, -1, sizeof pd);
		 memset(c, 0, sizeof c);
		 for(int i=0;i<n;i++) pd[i][i] = 1;

		 for(int i=1;i<n;i++){
			for(int j=0;j< n - i;j++){
				if(s[j] == s[i + j] and pd[j+1][i+j-1] == 1) pd[j][i+j] = 1;
				else if(i == 1 and s[j] == s[j+i]) pd[j][i+j] = 1;
				else pd[j][i+j] = 0;
			}		 	
		 }

		 cout << "Teste " << t++ << endl;

		 for(int i=0;i<n;i++){
		 	if(pd[0][i]){
		 		c[i] = 0;
		 	} else {
		 		c[i] = INT_MAX;
		 		for(int j=0;j<i;j++){
		 			if(pd[j+1][i] and 1 + c[j] < c[i]) c[i] = 1 + c[j];
		 		}
		 	}
		 }
		cout << c[n-1] + 1 << endl;
	}


	return 0;
}