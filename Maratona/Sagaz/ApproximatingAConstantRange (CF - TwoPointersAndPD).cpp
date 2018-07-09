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

int n;
vi vec(100001);
int last[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for(int i=0;i<n;i++) cin >> vec[i];

	int a = 0, b = 0;
	int ans = 1;
	int maxi = vec[0], mini = vec[0];
	int aa = 0, bb = 0;

	while(b < n){

		if(vec[b] == maxi) aa = b + 1;
		if(vec[b] == mini) bb = b + 1;
		last[vec[b]] = b + 1;

		if(vec[b] > maxi){
			maxi = vec[b];
			if(maxi - mini > 1)	a = last[mini], mini = vec[a];
			

		} else if(vec[b] < mini){
			mini = vec[b];
			if(maxi - mini > 1) a = last[maxi], maxi = vec[a];
		}
		ans = max(ans, b - a + 1);
		b++;
	}


	cout << ans << endl;

	return 0;
}