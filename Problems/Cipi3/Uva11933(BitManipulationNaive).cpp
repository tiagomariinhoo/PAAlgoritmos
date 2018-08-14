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

lli n;
string aux;
lli a, b;

void solve(){

	aux = "";
	a = 0, b = 0;

	while(n > 0){
		aux += (n%2) + '0';
		n/=2;
	}
	
	reverse(aux.begin(), aux.end());
	string aa = "", bb = "";
	bool at = false;
	// cout << aux << endl;
	for(int i=sz(aux)-1;i>=0;i--){
		// cout << aux[i] << endl;
		if(!at){
			if(aux[i] == '0') aa += '0', bb += '0';
			else aa += '1', bb += '0', at = true;
		} else {
			if(aux[i] == '0') aa += '0', bb += '0';
			else bb += '1', aa += '0', at = false;
		}
	}
	reverse(aa.begin(), aa.end());
	reverse(bb.begin(), bb.end());
	lli x = 0;
	for(int i=sz(aa)-1;i>=0;i--){
		a += (pow(2, x)) * (aa[i] - '0');
		x++;
	}

	x = 0;
	for(int i=sz(bb)-1;i>=0;i--){
		b += (pow(2, x)) * (bb[i] - '0');
		x++;
	}
	// cout << aa << " - " << bb << endl;
	cout << a << " " << b << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	while(cin >> n and n){
		solve();
	}

	return 0;
}
