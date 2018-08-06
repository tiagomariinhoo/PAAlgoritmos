#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};


int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<string, string>> vec;
	for(int i=0;i<n;i++){
		string a, b;
		cin >> a >> b;
		vec.pb({a,b});
	}

	int ans = 0;

	int aa = 0, bb = 0;
	bool at = false;
	int aaa = 0, bbb = 0;
	for(int i=0;i<sz(vec);i++){
		if(vec[i].F == "chuva"){
			if(!aaa) aa++;
			else aaa--;

			if(vec[i].S == "sol") bbb++;
			else {
				aaa++;
			}
		} else if(vec[i].F == "sol"){
			if(vec[i].S == "chuva"){
				if(!bbb) bb++,aaa++;
				else bbb--, aaa++;
			}
		}

	}

	cout << aa << " " << bb << endl;

	return 0;
}
