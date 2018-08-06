#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 100005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
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

int main(){
	string s;
	cin >> s;
	vi vec;
	for(int i=0;i<sz(s);i++){
		vec.pb(s[i]);
	}
	multiset<int> a;
	multiset<int>::iterator it;

	for(int i=0;i<sz(vec);i++){
		a.insert(vec[i]);
		it = a.upper_bound(vec[i]);
		if(it != a.end()) a.erase(it);
	}

	cout << sz(a) << endl;

	return 0;
}