#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100001
#define MIN -2000000
#define INF -9000000000000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ sol.cpp -std=c++11 -o sol.exe && sol.exe < in.txt
/* LowerBound and UpperBound iterator
*/
int pd[MAX];

int solve(int x, vi &c){
	if(x==0) return 1;
	if(x<0) return 0;
	if(pd[x]>=0) return pd[x];

	for(int i=0;i<sz(c);i++){
		if(solve(x - c[i] , c)) return pd[x-c[i]] = 1;
	}
	
	return 0;
}

int main(){
	int n;
	vi vec;
	int tot = 0;
	for(int i=0;i<n;i++){
		int a;
			cin >> a;
				vec.pb(a);
		tot+=a;
	}
	for(int i=0;i<=tot;i++)pd[i] = -1;

	if(solve(tot/2, vec)) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}