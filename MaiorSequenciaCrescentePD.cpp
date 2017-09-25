#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100001
#define MIN -2000000
#define INF (int)1e9
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
/* Maior subsequencia Crescente
	PD
*/

int n;

int lis(vi &v){
	vi pilha;
	for(int i=0;i<sz(v);i++){
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(),v[i]);
		if(it==pilha.end()) pilha.pb(v[i]);
		else *it = v[i];
	}
	return sz(pilha);
}

int main(){
	vi vec;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
			cin >> a;
				vec.pb(a);
	}
	cout << lis(vec) + 1 << endl;

	return 0;
}