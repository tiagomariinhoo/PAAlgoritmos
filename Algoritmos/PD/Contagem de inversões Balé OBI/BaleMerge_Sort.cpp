#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 1000000
#define MAXL 20
#define MIN -2000000
#define INF (1<<30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};


int merge_sort(vi &v){
	int inv = 0;
	if(sz(v) == 1) return 0;

	vi u1,u2;
	for(int i=0;i<sz(v)/2;i++) u1.pb(v[i]);
	for(int i = sz(v)/2; i<sz(v);i++) u2.pb(v[i]);


	inv += merge_sort(u1);
	inv += merge_sort(u2);

	u1.pb(INF);
	u2.pb(INF);

	int ini1=0,ini2=0;

	for(int i=0;i<sz(v);i++){
		if(u1[ini1] <= u2[ini2]) v[i] = u1[ini1], ini1++;
		else v[i] = u2[ini2], ini2++, inv += sz(u1) - ini1 - 1;
	}

	return inv;
}

int main(){
int n;
vi vec;

	cin >> n;
	for(int i=0;i<n;i++){
		int a;
			cin >> a;
				vec.pb(a);
	}

	cout << merge_sort(vec) << endl;


	return 0;
}