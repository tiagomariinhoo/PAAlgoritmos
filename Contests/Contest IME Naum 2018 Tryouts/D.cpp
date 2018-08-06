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
typedef pair<lli,lli> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;

lli test(lli mid){
	lli aa = ((mid*(mid+1))/2);
	return aa;
}	

lli solve(lli atual){

	 // cout << atual << endl;
	lli com = 0, fim = 10000000000;
	while(com < fim){
		lli mid = (com + fim + 1) >> 1;
		// cout << mid << endl;
		// cout << com << " - " << fim << endl;

		// cout << test(mid) << " - " << atual << endl; 
		if(test(mid) <= atual) com = mid;
		else fim = mid - 1;
	}
	return com;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// cout << LLONG_MAX << endl;
	// cout << test(1000000000000) << endl;

	// for(int i=1;i<=1000000;i++){
	// 	if(test(i) <= (LLONG_MAX)){
	// 		// cout << i << endl;
	// 	}
	// }

	cin >> n;
	for(int i=0;i<n;i++){
		lli a;
		cin >> a;
		cout << solve(a) << endl;
	}

	return 0;
}