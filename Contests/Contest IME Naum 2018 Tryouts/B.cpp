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
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

string s;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	int a = 1;
	char atual = s[0];
	string ans =( atual == 'C' ? "B" : "D");
	for(int i=1;i<sz(s);i++){
		if(s[i] == atual){
			a++;
			if(a == 3){
				a = 0;
				ans += (s[i] == 'C' ? "P" : "T");
			} else ans += (s[i] == 'C' ? "B" : "D");
		} else {
			a = 1, atual = s[i];
			ans += (s[i] == 'C' ? "B" : "D");
		}
	}

	cout << ans << endl;

	return 0;
}