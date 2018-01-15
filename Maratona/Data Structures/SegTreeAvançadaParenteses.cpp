#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
// #define lli unsigned long long int
#define lb long double
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

/*
	Dado uma string ()()(()())
	Dado um intervalo [i,j], saber
	o numero de elementos balanceados

*/

string s;
int n,m;
int t[2500000], o[2500000], c[25 d00000];

void build(int node = 1, int start = 0, int end = n-1){
	if(start == end){
		// cout << start << " - " << s[start] << " - " << node <<  endl;
		if(s[start] == '(') o[node] = 1;
		else c[node] = 1;
		return ;
	}

	int mid = (start + end) >> 1;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	int aa = min(o[2*node], c[2*node+1]);
	t[node] = t[2*node] + t[2*node+1] + aa;
	o[node] = o[2*node] + o[2*node+1] - aa;
	c[node] = c[2*node] + c[2*node+1] - aa;
}

pair<int, pair<int, int > > query(int l, int r, int node = 1, int start = 0, int end = n-1){
	if(r < start or end < l) return {0,{0,0}};
	if(l <= start and end <= r){
		pair<int, pair<int, int > > ans;
		ans.F = t[node];
		ans.S.F = o[node];
		ans.S.S = c[node];
		return ans;
	}	 
	int mid = (start + end) >> 1;
	pair<int, ii> p1 = query(l, r, 2*node, start, mid);
	pair<int, ii> p2 = query(l, r, 2*node+1, mid+1, end);

	int temp, T, O, C;
	temp = min(p1.S.F, p2.S.S);
	T = p1.F + p2.F + temp;
	O = p1.S.F + p2.S.F -  temp;
	C = p1.S.S + p2.S.S - temp;
	pair<int, pair<int, int > > ans;
	ans.F = T;
	ans.S.F = O;
	ans.S.S = C;
	return ans;
}

int main(){
	// cout << sz(s);
	// s+="'";
	// cout << " " << sz(s) << endl;
	// s.insert("");
	cin >> s;
	cin >> m;
	n = sz(s);
	build();

	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		pair<int, pair<int, int > > aa = query(a-1,b-1);
		cout << aa.F*2 << endl;
	}


	return 0;
}