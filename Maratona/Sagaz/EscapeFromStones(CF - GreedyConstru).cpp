#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF 999998
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
//\n

vi a,b;
string s;

int main(){
	cin >> s;

	for(int i=0;i<sz(s);i++){
		if(s[i] == 'l'){
			a.pb(i+1);
		} else b.pb(i+1);
	}

	for(int i=0;i<sz(b);i++) printf("%d\n", b[i]);

	for(int i=sz(a)-1;i>=0;i--) printf("%d\n", a[i]);

	return 0;
}