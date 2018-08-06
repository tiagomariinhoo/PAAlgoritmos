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

int f,p,e,a;
lli troca;

int main(){
	ios_base::sync_with_stdio(false);
	while(1){
	lli pd[5001][21];
	vi vec[5001];
		cin >> f >> p >> e >> a;
		if(!f and !p and !e and !a) break;
		troca = e * a;
		// memset(pd, 919191, sizeof pd);
		for(int i=1;i<=p;i++){
			for(int j=0;j<f;j++){
				lli aa,bb;
				cin >> aa >> bb;
				vec[i].pb(aa * bb);
			}
		}
 
		for(int i=1;i<=p;i++){
			for(int j=0;j<f;j++) pd[i][j] = INF;
		}
 
		for(int i=0;i<f;i++){
			pd[1][i] = vec[1][i];
			if(i!=0) pd[1][i] += troca;
		}
 
		for(int i=2;i<=p;i++){
			for(int j=0;j<f;j++){
				for(int k=0;k<f;k++){
					if(j != k) pd[i][j] = min(pd[i][j], pd[i-1][k] + vec[i][j] +  (troca));
					else pd[i][j] = min(pd[i][j], pd[i-1][k] + vec[i][j]);
				}
			}
		}
 
		// for(int i=1;i<=p;i++){
		// 	for(int j=0;j<f;j++) cout << pd[i][j] << " ";
		// 		cout << endl;
		// }
 
		lli aa = INF;
		for(int i=0;i<f;i++) aa = min(aa, pd[p][i]);
 
		cout << aa << endl;
	}
 
	return 0;
} 