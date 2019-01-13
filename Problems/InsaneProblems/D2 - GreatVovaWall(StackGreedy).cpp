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

int n;
vi vec;

int no(int pos){
	// cout << pos << endl;
	cout << "NO" << endl;
	exit(0);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
  	int a;
  	cin >> a;
  	vec.pb(a);
  }

  if(n == 1){
  	cout << "YES" << endl;
  	return 0;
  }


  bool need = false, at = false;
  int count = 0;

  stack<int> q;

  int maxi = 0;
  for(int i=0;i<sz(vec);i++){
  	maxi = max(maxi, vec[i]);
  	if(!i){
  		if(vec[i] > vec[i+1]){
  			q.push(vec[i]);
  		} else if(vec[i] == vec[i+1]){
  			i++;
  		} else no(i);
  	} else {
  		if(!q.empty()){
  			if(q.top() > vec[i]) q.push(vec[i]);
  			else if(q.top() == vec[i]) q.pop();
  			else {
  				no(i);
  			}
  		} else {
  			q.push(vec[i]);
  		}
  	}
  }

  if(sz(q) > 1) no(0);
  else if(!q.empty() and q.top() < maxi) no(0);

  cout << "YES" << endl;

  return 0;
}