#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF 10000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
/*
	Two Pointers
	Dado um array de tamanho n
	Pegar a maior soma dentro do array, que não seja maior que 'm'
*/

int main(){

	int n,m;
	ss(n,m);
	vi vec;
	for(int i=0;i<n;i++){
		int a;
			cin >> a;
				vec.pb(a);
	}

	int l = 0, r = 0;
	int sum = 0, ans = 0;
	while(l < n){
		while(r < n && vec[r] + sum <= m){
			sum += vec[r];
			r++;
		}
		ans = max(ans, sum);
		sum -= vec[l];
		l++;
	}
	cout << ans << endl;
	return 0;
}