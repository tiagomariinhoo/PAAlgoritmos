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
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
vector<pair<ii, ii> > vec(140000);
pair<ii, ii> pre[140000], suf[140000];

pair<ii, ii> soma(pair<ii,ii> a, pair<ii,ii> b){
	return { { max(a.F.F, b.F.F), max(a.F.S, b.F.S) }, { min(a.S.F, b.S.F), min(a.S.S, b.S.S) } };
}

bool can(pair<ii, ii> a, pair<ii, ii> b){

}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++){
  	int a, b, c, d;
  	cin >> a >> b >> c >> d;
  	vec[i].F.F = a, vec[i].F.S = b, vec[i].S.F = c, vec[i].S.S = d;
  }

  pre[0].F.F = -INF, pre[0].F.S = -INF, pre[0].S.F = INF, pre[0].S.S = INF;
  suf[n+1].F.F = -INF, suf[n+1].F.S = -INF, suf[n+1].S.F = INF, suf[n+1].S.S = INF;
  pre[1] = vec[1];
  suf[n] = vec[n];
  for(int i=1;i<n;i++){
  	pre[i] = soma(pre[i-1], vec[i]);
  }

  for(int i=n;i>=1;i--){
  	suf[i] = soma(suf[i+1], vec[i]);
  }

  for(int i=1;i<=n;i++){
  	pair<ii, ii> aux = soma(pre[i-1], suf[i+1]);
  	if(aux.F.F <= aux.S.F and aux.F.S <= aux.S.S){
  		cout << aux.F.F << " " << aux.F.S << endl;
  		return 0;
  	}
  }
 

  return 0;
}