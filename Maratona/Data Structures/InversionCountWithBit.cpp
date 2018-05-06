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

int tree[100001];
int n;
void atualiza(int x, int v){
	for(;x<=n;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
	int s = 0;
	for(;x>0;x-=(x&-x)) s += tree[x];
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	while(1){
		cin >> n;
		vi vec;
		memset(tree, 0, sizeof tree);
		if(n == 0) break;
		for(int i=0;i<n;i++){
			int a;
			cin >> a;
			vec.pb(a);
		}

		int ans = 0;
		for(int i=sz(vec)-1;i>=0;i--){
			atualiza(vec[i], 1);
			ans += sum(vec[i] - 1);
		}
		if(ans%2!=0) cout << "Marcelo" << endl;
		else cout << "Carlos" << endl;

	}


	return 0;
}