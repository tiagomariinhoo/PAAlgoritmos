#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (500000000)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
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

int n,m;
int pai[1000000];
int peso[1000000];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y) return ;

	if(peso[x] < peso[y]){
		pai[x] = y;
	} else if(peso[x] > peso[y]){
		pai[y] = x;
	} else {
		pai[x] = y;
		peso[y]++;
	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) pai[i] = i;
	for(int i=0;i<m;i++){
		char c;
		int a,b;
		cin >> c >> a >> b;
		if(c == 'C'){
			if(find(a) == find(b)) cout << "S" << endl;
			else cout << "N" << endl;
		} else {
			join(a,b);
		}
	}

	return 0;
}