#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
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
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n, m, k;
map<ii, int> vis;
bool at = false;
vector<int> qts;

ii proc(int x, int y){
	if(!at){
		if(y < m) return {x, y+1};
		else if(y == m){
			at = true;
			return {x+1, y};
		}
	} else {
		if(y > 1) return {x, y-1};
		else if(y == 1){
			at = false;
			return {x+1, y};
		}
	}
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  int qt = (n*m)/k;

  // if((n*m)%k != 0){
  	int sum = 0;
  	for(int i=0;i<k;i++) qts.pb((n*m)/k), sum += qts[i];

  	qts[sz(qts) - 1]+=  (n*m) - sum;

  // }

  // for(int i=0;i<qts.size();i++) cout << qts[i] << " ";
  // 	cout << endl;

  int x = 1, y = 0;

  for(int i=0;i<sz(qts);i++){
  	cout << qts[i] << " ";
  	for(int j=0;j<qts[i];j++){

  		ii aux = proc(x, y);
  		x = aux.F, y = aux.S;

  		cout << aux.F << " " << aux.S << " ";

  	} cout << endl;
  }

  return 0;
}