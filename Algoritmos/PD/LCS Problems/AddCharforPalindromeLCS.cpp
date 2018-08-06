#include <bits/stdc++.h>
 
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 500
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
// #define lli unsigned long long int
#define lb long double
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//ios_base::sync_with_stdio(false);
//g++ -std=c++11 sol.cpp -o sol.exe && sol.exe < in.txt > output.txt
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
string a,b;
int pd[5002][5002];

int lcs(){
	for(int i=0;i<=sz(a);i++){
		for(int j=0;j<=sz(b);j++){
			if(i==0 or j==0) pd[i][j] = 0;
			else if(a[i-1] == b[j-1]) pd[i][j] = pd[i-1][j-1] + 1;
			else pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
		}
	}
	// cout << "Pd : " << pd[sz(a)][sz(b)] << endl;
	return sz(a) - pd[sz(a)][sz(b)];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> a;
	string aux = a;
	reverse(aux.begin(), aux.end());
	b = aux;

	cout << lcs() << endl;


	return 0;
}