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

int t;
int n;
int mm;
int resposta = 99999;
unsigned int dd[101];

void knap(int obj, unsigned int ans, int qt){
	if( __builtin_popcount(ans)  >= mm){
		resposta = min(resposta, qt);
		return ;
	} 
	if(obj == n) return ;

	knap(obj+1, ans, qt);
	ans |=  dd[obj];
	knap(obj+1, ans, qt+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> t;	
	while(t--){
		int m,d;
		cin >> m >> d;
		n = d;
		mm = m;
		resposta = 99999;
		
		for(int i=0;i<50;i++) dd[i] = 0;

		for(int i=0;i<d;i++){
			int c;
			cin >> c;
			vi aux;
			for(int j=0;j<c;j++){
				unsigned int a;
				cin >> a;
				cout << "a : " << a << " - " << (1<<a) << endl;
				dd[i] = dd[i] | (1<<a);
				bitset<32> x(dd[i]);
				cout << x << endl;
			}
		}
		unsigned int ans = 0;
		knap(0, ans, 0);
		if(resposta == 99999) cout << "Desastre!" << endl;
		else cout << resposta << endl;
	}

	return 0;
}