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
 
int t[1001], p[1001], q[1001];
 
int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int tt;
	cin >> tt;
	t[1] = 1, p[1] = 2, q[1] = 1;
	t[2] = 5, p[2] = 7, q[2] = 6;
	// t[2] = 5, p[2] = 2, q[2] = 1;
	for(int i=3;i<=1001;i++){
		t[i] = t[i-1] + t[i-2] + 2*p[i-2] + q[i-2];
		q[i] = t[i] + q[i-2];
		p[i] = t[i] + p[i-1];
	}
 
	for(int i=1;i<=tt;i++){
		int n;
		cin >> n;
 
		cout << i << " " << t[n] << endl;
	}
 
	return 0;
} 