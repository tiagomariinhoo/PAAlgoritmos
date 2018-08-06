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

string s;

lli pd[5001][2];

lli solve(int obj, int dif){
	if(obj == sz(s)) return 1;
	if(pd[obj][dif] != -1) return pd[obj][dif];

	lli &ans = pd[obj][dif];
	lli a = 0;

	// if(s[obj] == '0') a += solve(obj+1, 1);
	if(s[obj] != '0'){
		if(obj < sz(s) - 1){
			if(s[obj+1] != '0') a += solve(obj+1, 1);
		} else a += solve(obj+1, 1);
	}

	if(obj < sz(s) - 1){
		// cout << s[obj] << " - " << s[obj+1] << endl;
		if(s[obj] == '1' and s[obj+1] <= '9' or (s[obj] == '2' and s[obj+1] <= '6')){
			if(obj < sz(s) - 2){
				if(s[obj+2] != '0') a += solve(obj+2, 2);
			} else {
				a += solve(obj+2, 2);
			}
		}
	}


	return ans = a;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> s){
		if(sz(s) == 1 and s[0] == '0') break;
		memset(pd, -1, sizeof pd);

		cout << solve(0, 1) << endl;
	}


	return 0;
}
