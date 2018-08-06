#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 10000001
#define MIN -2000000
#define INF (int)1e9
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define MOD 1000000007 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
//ios_base::sync_with_stdio(false);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

lli x,y;
lli n;
vector<lli> vec;
/*
	Numero%MOD + MOD)%MOD , para não dar problema com o negativo
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin >> x >> y >> n;
	// vec.pb();	
	// cout << (-2000000000%MOD + MOD)%MOD << endl;
	vec.pb(x), vec.pb(y),vec.pb(y - x);
	if(n == 1){
		cout << (x%MOD + MOD)%MOD << endl;
		return 0;
	} else if(n==2){
		cout <<(y%MOD + MOD)%MOD << endl;
		return 0;
	}

	// cout << vec[0] << " - " << vec[1] << " - " << vec[2] << endl;

	lli aux = n/3;
	if(n%3 != 0) aux++;

	lli ans = n%3;
	lli anss = 0;
	if(ans == 0){
		anss = vec[2];
	} else if(ans == 1){
		anss = vec[0];
	} else if(ans == 2){
		anss = vec[1];
	}
	// cout << anss << " - " << ans << " - " << aux << endl;

	if(aux%2==0) anss = anss*-1;

	cout << (anss%MOD + MOD) % MOD << endl;

	return 0;
}0