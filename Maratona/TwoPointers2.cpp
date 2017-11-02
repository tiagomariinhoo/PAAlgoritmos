#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF 1000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(i,a,n) for(int i=0;i<n;i++) cin >> a, vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second

 /*
	Two Pointers - 2
	Dado um array de n elementos, encontrar o menor subarray
	contido que contem pelo menos k elementos distintos.
 	Caso contrário imprime -1
 */

int main(){

	int n,k,a;
	ss(n,k);
	vi vec;
	ler(i,a,n);

	int l=0, r=0, ans = INF;
	map<int, int > cnt;
	set <int> s;
	while(l < n){
		while(r < n && s.size() < k) {
			s.insert(vec[r]);
			cnt[vec[r]]++;
			r++;
		}
		if(s.size() >= k) ans = min(ans, r - l);
		if(cnt[vec[l]] == 1) s.erase(vec[l]);
		cnt[vec[l]]--;
		l++;
	}

	if(ans == INF) ans = -1;
	cout << ans << endl;

	return 0;
}