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
// #define lli long long int
#define lli unsigned long long int
#define lb long double
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//ios_base::sync_with_stdio(false);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

 
int main(){

	int n;
	while(s(n)!=EOF){
		vi vec;
		lli sum = 0;
		lli s[100000];
		for(int i=0;i<n;i++){
			int a;
				cin >> a;
				sum += a;

				if(a!=0)
					vec.pb(a);
		}
		if(sum%3!=0){
			cout << 0 << endl;
			continue;
		}
		s[0] = vec[0];
		for(int i=1;i<n;i++) s[i] = s[i-1] + vec[i];
		

		lli aux = sum/3, ans = 0;

		int a = 0, b = 1, c = 2, d = 0;
		int aa = 0, bb = 0, cc = 0;
		// int ans = 0;

		// for(int i=0;i<n;i++){
		// 	for(int j=i+1;j<n;j++){
		// 		if(s[j] - s[i] == aux){
		// 			for(int k = j+1;k < n;k++) if(s[k] - s[j] == aux) ans++;
		// 		}
		// 	}
		// }

		while(c < n){
			int aaa = s[b] - s[a];
			if(aaa > aux){
				a++;
				if(a == b){
					b++;
					if(b == c) c++;
				}
			} else if(aaa < aux){
				b++;
				if(b==c) c++;
			} else {
				int bbb = s[c] - s[b];
				if(bbb > aux){
					b++;
					if(b == c) c++;
				} else if(bbb < aux){
					c++;
				} else {
					ans++;
					a++;
				}
			}
			// cout << a << " - " << b << " - " << c << endl;
			// cout << aaa << endl;
		}
		cout << ans << endl;
	}

	return 0;
}