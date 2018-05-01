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

int n;
vector<string> vec;
set< set<char> > ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		vec.pb(s);
	}

	for(int i=0;i<sz(vec);i++){
		set<char> aux;
		for(auto j : vec[i]){
			aux.insert(j);
		}
		ans.insert(aux);
	}
	cout << sz(ans) << endl;
	
	return 0;
}