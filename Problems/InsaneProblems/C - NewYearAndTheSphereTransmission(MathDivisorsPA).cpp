#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
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
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 200010
#define MAXL 20

lli n;
set<lli> ans;

/*
	Pega os divisores e joga em uma PA
	Nice Problem	
*/

void solve(){
	for(lli i=1;i<=sqrt(n);i++){
		if(n%i == 0){
			if(n/i == i){
				lli atual = ((1 + (n+1 - i))*(n/i))/2;
	  		ans.insert(atual);
			} else {
				lli x = i, y = n/i;

				lli atual = ((1 + (n+1 - x))*(n/x))/2;

				lli atual2 = ((1 + (n+1 - y))*(n/y))/2;
	  		ans.insert(atual);
	  		ans.insert(atual2);
			}
		}
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  solve();

  ans.insert(1), ans.insert((n*(n+1))/2);
 	for(auto i : ans) cout << i << " ";
 	cout << endl;

  return 0;
}  