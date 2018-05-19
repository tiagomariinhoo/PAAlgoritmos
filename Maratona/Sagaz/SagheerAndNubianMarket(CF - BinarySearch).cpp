#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999999
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

int n, s;
vector<ii> vec;
int ans, ans2;
int ans3, ans4;
bool check(int x){
	int sum = 0;
	vi vec2;
	for(int i=0;i<sz(vec);i++){
		vec2.pb(vec[i].F + (vec[i].S * x));
	}
	sort(vec2.begin(), vec2.end());
	for(int i=0;i<x;i++){
		sum += vec2[i];
		if(sum > s) return false;
	}
	if(x > ans){
		ans = x;
		ans2 = sum;
	}
	return true;
}

void bin(){
	int com = 0, fim = sz(vec);
	while(com <= fim){
		int mid = (com + fim) >> 1;
		if(check(mid)){
			com = mid + 1;
			// cout << "Agora : " << com << endl;		
		} else fim = mid - 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> s;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb({a, i+1});
	}
	// sort(vec.begin(), vec.end());
	bin();

	cout << ans << " " << ans2 << endl;

	return 0;
}