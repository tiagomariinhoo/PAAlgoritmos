#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 9999999999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
 
lli f,p,e,a;
lli troca;
lli pd[5001][21];
vi vec[5001];
 
lli knap(int pp, int ff){
	if(pp == p + 1) return pd[pp][ff] = 0;
	if(pp == p){
		lli aa = INF;
		for(int i=0;i<f;i++){
			lli aaa = vec[pp][i];
			if(i != ff) aaa += troca;
			aa = min(aa, aaa);
		}
		pd[pp][ff] = aa;
	}
	if(pd[pp][ff] != -1) return pd[pp][ff];
 
	lli aa = INF;
	
	for(int i=0;i<f;i++){
		lli aaa = knap(pp + 1, i) + vec[pp][i];
		if(i != ff) aaa += troca;
		aa = min(aa, aaa);
	}
 
	return pd[pp][ff] = aa;
}	
 
int main(){
	ios_base::sync_with_stdio(false);
	while(1){
		cin >> f >> p >> e >> a;
		// cout << f << " - " << p << " - " << e << " - " << a << endl;
		if(!f and !p and !e and !a) break;
		troca = e * a;
		for(int i=0;i<=p;i++) vec[i].clear();
		// vec.clear();
		// memset(pd, INF, sizeof pd);
		for(int i=0;i<=p;i++) for(int j=0;j<=f;j++) pd[i][j] = -1;
 
		for(int i=1;i<=p;i++){
			for(int j=0;j<f;j++){
				lli aa,bb;
				cin >> aa >> bb;
				vec[i].pb(aa * bb);
			}
		}
 
		knap(1, 0);
 
		// for(int i=1;i<=p;i++){
		// 	for(int j=0;j<f;j++) cout << pd[i][j] << " ";
		// 		cout << endl;
		// }
 
		lli aa = INF;
 
		// for(int i=1;i<=p;i++){
		// 	for(int j=0;j<f;j++) cout << pd[i][j] << " ";
		// 		cout << endl;
		// }
 
		for(int i=0;i<f;i++){
			if(pd[1][i] == -1) continue;
			 aa = min(aa, pd[1][i]);
		}
 	// cout << endl;
 
		cout << aa << endl;
	}
 
	return 0;
}   