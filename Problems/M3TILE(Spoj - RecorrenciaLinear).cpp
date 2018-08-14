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

unsigned long long int vec[32];
int n;

int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	vec[0] = 1, vec[1] = 0, vec[2] = 3, vec[3] = 0;
	// for(int i=4;i<=10000001;i++) vec[i] = ((4*(vec[i-2]))%MOD - (vec[i-4]%MOD))%MOD;

	for(int i=4;i<=31;i++){
		vec[i] = ((4*vec[i-2]) - vec[i-4])%MOD;
	}


	while(1){
		int n;
		s(n);
		if(n == -1) break;
		cout << vec[n] << endl;
	}

	return 0;
}