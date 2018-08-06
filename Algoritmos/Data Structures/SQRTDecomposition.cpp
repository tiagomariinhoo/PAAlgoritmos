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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

#define MAXNN 50000
#define SQRSIZE 500

lli vec[MAXNN];
lli block[SQRSIZE];
lli blockSize;
lli n;

void update(int idx, int val){
	int pos = idx/blockSize;
	block[pos] += val - vec[idx];
	vec[idx] = val;
}

lli query(int l, int r){
	lli sum = 0;
	while(l < r and l%blockSize!=0 and l != 0){
		sum += vec[l];
		l++;
	}
	while(l+blockSize <= r){
		sum += block[l/blockSize];
		l+= blockSize;
	}
	while(l<=r){
		sum += vec[l];
		l++;
	}
	return sum;
}

void build(){
	int blockIdx = -1;
	blockSize = sqrt(n);

	for(int i=0;i<n;i++){
		if(i%blockSize == 0) blockIdx++;
		block[blockIdx] += vec[i];
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i=0;i<n;i++) cin >> vec[i], vec[i] < 0 ? vec[i] = 0 : 0;
	build();

	int m;
	cin >> m;
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		cout << query(a-1, b-1) << endl;
	}



	return 0;
}