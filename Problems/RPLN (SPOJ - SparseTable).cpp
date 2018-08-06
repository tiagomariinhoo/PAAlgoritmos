#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 99999999
#define MAXL 20
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
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int a[100001];
int spt[100001][17];
int n,m;

void build(){
	for(int j=0;(1 << j) <= n ; j++){
		for(int i=0; (i + (1 << j) - 1) < n; i++){
			if(j){
				int pos = spt[i][j-1];
				int pos2 = spt[i+(1 << (j-1))][j-1];
				spt[i][j] = a[pos] < a[pos2] ? pos : pos2;
			} else {
				spt[i][j] = i;
			}
		}
	}
}

int rmq(int i, int j){
	int len = j - i + 1;
	int k = (int) floor(log((double) len) / log(2.0));
	if(a[spt[i][k]] <= a[spt[j-(1<<k)+1][k]]){
		return spt[i][k];
	} else {
		return spt[j - (1 << k) + 1][k];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int k = 1;
	while(k <= t){
		int q;
		cin >> n >> q;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}

		build();


		cout << "Scenario #" << k << ":" << endl;
		for(int i=0;i<q;i++){
			int aa,bb;
			cin >> aa >> bb;
			cout << a[rmq(aa-1, bb-1)] << endl;
		}
	
		k++;
	}

	return 0;
}