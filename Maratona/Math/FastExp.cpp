#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF 10000000
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

/*
	Modular Exponentiation
	x,y and p
	x^y) % p , ex : 2 3 5, 2^3%5 = 8%5 = 3
	Calculate in O(Log Y)
*/

int fexp(int x, int y){ //Calcula x^y em Log Y
	int ans = 1;
	while(y>0){
		if(y&1) ans*=x; //y&1 verifica se é impar
		y = y >> 1;
		x*=x;
	}
	return ans;
}

int modFexp(int x, int y, int p){ //Calcula x^y%p em Log Y
	int ans = 1;
	while(y > 0){
		if(y&1) ans = (ans*x) % p;
		y = y >> 1;
		x = (x*x) % p;
	}
	return ans;
}



int main(){

	int a,b,c;
	cin >> a >> b >> c;

	cout << fexp(a,b) << endl;
	cout << modFexp(a,b,c) << endl;

	return 0;
}