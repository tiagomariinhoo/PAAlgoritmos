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

int a[MAX];

int ternary_search(int l, int r, int x){
	if(r>=l){
		int mid1 = l + (r-l)/3;
		int mid2= r - (r-l)/3;
	
		if(a[mid1] == x) return mid1;
		if(a[mid2] == x) return mid2;
		if(x < a[mid1]) return ternary_search(l, mid1-1,x);
		else if(x > a[mid2]) return ternary_search(mid2+1, r, x);
		else return ternary_search(mid1+1, mid2-1, x);
	}
	return -1;
}

int main(){
	int n;
	cin >> n;

	for(int i=0;i<n;i++) cin >> a[i];

	cout << ternary_search(0,n,5) << endl;

	return 0;
}