#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(0)
#define MAXN 50500
#define MAX 100000
#define MAXL 20
#define MIN -2000000
#define INF (1<<30)
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
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int iii = 0;
lli ff(lli x){
	return ((lli)2*(x*x)) - ((lli)12*x) + 7;
}

lli ternary_search(lli l, lli r){
		lli mid1,mid2;
		lli ans = 100000000000000;
		if(iii) cout << " ---- " << endl;
	if(l <= r){
		for(int i=0;i<50;i++){
		mid1 = l + (r-l)/3;
		mid2 = r - (r-l)/3;
		if(iii)cout << ff(mid1) << " - " << ff(mid2) << endl;
		lli a = ff(mid1);
		lli b = ff(mid2);
		if(iii)cout << a << " - " << b << endl;
		if(a < b) ans = min(ans,a), r = mid2;
		else l = mid1, ans = min(ans,b);
		}
	}
	if(iii)cout << "Ans : " << ans << endl;
	if(iii)cout << " ---- " << endl;
	return ans;
}

int main(){

	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		lli a,b;
		cin >> a >> b;
		if(i == 1) iii = 1;
		else iii = 0;
		cout << ternary_search(a,b) << endl;
	}


	return 0;
}