#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (10000000000000)
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

lli ans[1000005];

int main(){
lli n,a,b;

	cin >> n >> a >> b;
	// if(a > b) swap(a,b);
	if(a == 1 or b == 1){
		for(int i=1;i<=n;i++) cout << i << " ";
			cout << endl;
		return 0;
	}

	int aa = -1, bb = -1;
	bool at = false;

	for(lli i=0;i<=1000000;i++){
		if((n - i*a) % b == 0 and i*a <= n){
			// cout << i*a << endl;
			aa = i;
			bb = (n-i*a)/b;
			break;
		}
	}

	// cout << aa << " " << bb << endl;
	if(aa < 0 or bb < 0){
		cout << -1 << endl;
		return 0;
	}

	vi groups;
	if(aa > 0)
	for(int i=0;i<aa;i++) groups.pb(a);
	if(bb > 0)
	for(int i=0;i<bb;i++) groups.pb(b);
	int numb = 1;
	int pos = 1;
	int tam = 0;
	vi anss;
	// cout << sz(groups) << endl;
	for(int i=0;i<sz(groups);i++){
		
		ans[groups[i] - 1] = numb++;
		for(int j=0;j<groups[i]-1;j++) ans[j] = numb++;


		for(int j=0;j<groups[i];j++) anss.pb(ans[j]);
	}
	
	// cout << "Numb : " << numb << endl;
	for(int i=0;i<sz(anss);i++) cout << anss[i] << " ";
		cout << endl;

 	return 0;
}