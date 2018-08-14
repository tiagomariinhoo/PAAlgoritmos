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

int n;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int a = sqrt(n);

	vector< vi > vec;
	int i = 1;
	while(i <= n){
		vi aux;
		for(int j=0;j<a;j++){
			aux.pb(i);
			i++;
			if(i > n) break;
		}
		vec.pb(aux);
	}

	sort(vec.begin(), vec.end());

	for(int i=sz(vec)-1;i>=0;i--){
		for(auto j : vec[i]){
			cout << j << " ";
		}
	}

	return 0;
} 