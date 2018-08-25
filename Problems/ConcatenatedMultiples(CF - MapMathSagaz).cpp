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

int n, k;
vi vec;
vi aux;
vector<int> resto[20];
unordered_map<int, int> qt[20];

int count(lli x){
	int a = 1;
	while(x >= 10){
		a++;
		x/=10;
	}
	return a;
}

lli fexp(lli x, lli y){ //Calcula x^y em Log Y
	lli ans = 1;
	while(y>0){
		if(y&1) ans*=x; //y&1 verifica se é impar
		y = y >> 1;
		x*=x;
	}
	return ans;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // cout << 200000 << " " << 1000000000 << endl;
  // for(int i=0;i<200000;i++) cout << 1000000000 << " ";
  // 	cout << endl;

  cin >> n >> k;
  for(int i=0;i<n;i++){
  	int a;
  	cin >> a;
  	vec.pb(a);
  }

  for(int i=0;i<sz(vec);i++){
  	// cout << count(vec[i]) << " " << vec[i]%k << endl;
  	qt[count(vec[i])][vec[i]%k]++;
  }


  lli ans = 0;
  for(int i=0;i<sz(vec);i++){
  	// cout << "Vec i : " << vec[i] << endl;
  	for(int j=1;j<=10;j++){
  		lli xx = fexp(10, j);
  		lli value = vec[i]*xx;
  		lli atual = (value)%k;
  		// cout << vec[i] << " -- " << xx << endl;
  		// cout << value << " - " << atual << endl;
  		if(atual == 0) atual = k;
  		// cout << qt[j][k - atual] << endl;
  		ans += qt[j][k - atual];
  		if(j == count(vec[i]) and k - atual == vec[i]%k) ans--;
  	}
  }

  cout << ans << endl;


  return 0;
}