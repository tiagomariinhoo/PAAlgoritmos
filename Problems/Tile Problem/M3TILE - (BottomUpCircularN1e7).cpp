#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
 
int n;
lli pd[1000][5];
 
// int solve(int j, int mask){
// 	if(j == n){
// 		if(!mask) return 1;
// 		return 0;
// 	}
// 	if(pd[j][mask] != -1) return pd[j][mask];
 
// 	int &ans = pd[j][mask];
// 	ans = 0;
// 	int a = 0;
 
// 	if(mask == 0){
// 		a += solve(j+1, 1) + solve(j+1, 4) + solve(j+2, 0);
// 	} else if(mask == 1){
// 		a += solve(j+1, 0) + solve(j+1, 6);
// 	} else if(mask == 3){
// 		a += solve(j+1, 4);
// 	} else if(mask == 4){
// 		a += solve(j+1, 0) + solve(j+1, 3);
// 	} else if(mask == 6){
// 		a += solve(j+1, 1);
// 	}
 
// 	return ans = a;
// }
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	// while(1){
		cin >> n;
		// if(n == -1) break;
		// for(int i=0;i<=30;i++) for(int j=0;j<=8;j++) pd[i][j] = -1;
 	
 		if(n%2!=0){
 			cout << 0 << endl;
 			return 0;
 		}

 		pd[0][0] = 1;
 		// cout << n << endl;
		for(int i=1;i<=n;i++){
			int ii = i%1000;
			int atual = ii-1;
			int atual2 = ii-2;
			if(ii == 0) atual = 999, atual2 = 998;
			if(ii == 1) atual2 = 999;

			// cout << ii << endl;
			// cout << atual << " - " << atual2 << endl;
			pd[ii][0] = (pd[atual][1]%MOD + pd[atual][4]%MOD + pd[atual2][0]%MOD)%MOD;
			pd[ii][1] = (pd[atual][0]%MOD + pd[atual][2]%MOD)%MOD;
			pd[ii][3] = pd[atual][4]%MOD;
			pd[ii][4] = (pd[atual][0]%MOD + pd[atual][3]%MOD)%MOD;
			pd[ii][2] = pd[atual][1]%MOD;
		}
		cout << pd[n%1000][0]%MOD << endl;
	// }
 
	return 0;
} 