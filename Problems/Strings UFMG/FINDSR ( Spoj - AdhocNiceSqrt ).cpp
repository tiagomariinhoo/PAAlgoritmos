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
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
// int ddx[] = {1, 0};

/*
	Prefixo tem que ser divisor
	Phi = numero de divisores de sz(s)
	Complexidade : Sz(s) * phi(sz(s))
*/

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(1){
		string s;
		cin >> s;
		if(sz(s) == 1 and s[0] == '*') break;

		set<int> aux;
		int n = sz(s);
		for(int i=1;i<=sz(s);i++){
			if(n%i==0){
				if(n/i == i) aux.insert(i);
				else aux.insert(i), aux.insert(n/i);
			}
		}

		for(auto i : aux){
			bool at = false;
			for(int j=0;j<sz(s);j++){
				if(s[j] != s[j%i]){
					at = true;
					break;
				}
			}
			if(!at){
				cout << sz(s) / i << endl;
				break;
			}
		}

	}

	return 0;
}