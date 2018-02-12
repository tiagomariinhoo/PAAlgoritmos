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
 
int nn;
 
unsigned int a[25];
int anss = 0;
 
void knap(int obj, unsigned int ans, unsigned int qt){
	if(obj == nn+1) return ;
	
	anss = max(anss, __builtin_popcount(qt));
 
	knap(obj+1, ans, qt);
	if(!(qt & (a[obj])) and !(ans & (1 << obj)))
	knap(obj+1, ans |= a[obj], qt |= (1 << obj));
 
	anss = max(anss, __builtin_popcount(qt));
}
 
 
int main(){
	int n;
	int aaa = 1;
		while (1){
		cin >> n;
		if(n==0){
			break;
		}
		nn = n;
		memset(a, 0, sizeof a);
		anss = 0;
		for(int i=0;i<n;i++){
			int j = 1;
			while(1){
				int x;
					cin >> x;
					if(x == 0) break;
				a[i+1] |= (1 << x);
			}
		} 
		knap(1, 0, 0);
		cout << "Teste " << aaa++ << endl;
		cout << anss << endl;
		cout << endl;
	}
 
 
	return 0;
}  