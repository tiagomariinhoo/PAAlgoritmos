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
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
#define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};


lli a, b, c;
lli pd[10][2][100][100];

string to_string(int t) {
  stringstream ss;
  ss << t;
  return ss.str();
}


string vec;

lli solve(int pos, int can, lli sum, lli rem){
	if(pos == sz(vec)){
		return (sum == 0 and rem == 0);
	}
	lli &ans = pd[pos][can][sum][rem];
	if(ans != -1) return ans;
	int atual = can ? vec[pos]-'0' : 9;
	lli aux = 0;
	for(int i=0;i<=atual;i++){
		if(i == atual) aux += solve(pos+1, can, (sum+i)%c, ((rem*10) + i)%c);
		else aux += solve(pos+1, 0, (sum+i)%c, ((rem*10)+i)%c);
	}
	return ans = aux;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	int tt = 1;
	while(tt <= t){
		cin >> a >> b >> c;

		memset(pd, -1, sizeof pd);

		vec = to_string(a-1);
		lli ans = solve(0, 1, 0, 0);
		vec = to_string(b);
		memset(pd, -1, sizeof pd);
		ans *= -1;
		ans += solve(0, 1, 0, 0);
		cout << "Case " << tt << ": ";
		if(c >= 100){
			cout << 0 << endl;
			tt++;
			continue;
		}

		cout << (ans) << endl;
		tt++;
	}

	return 0;
}