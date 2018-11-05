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
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20
#define MOD2 998244353

lli n, m, k;
vi vec;

bool solve(int pos){
	lli aux = 0, sum = 0;
	for(int i=sz(vec)-1;i>=pos;i--){
		if(sum + vec[i] > k){
			sum = vec[i];
			aux++;
		} else {
			sum += vec[i];
		}
	}
	if(sum > 0) aux++;
	// cout << pos << " " << aux << endl;
	return aux <= m;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;

  for(int i=0;i<n;i++){
  	int a;
  	cin >> a;
  	vec.pb(a);
  }

  int com = 0, fim = n-1;
  while(com < fim){
  	int mid = (com + fim) >> 1;
  	if(solve(mid)) fim = mid;
  	else com = mid+1;
  }
  cout << n - fim << endl;

    return 0;
}