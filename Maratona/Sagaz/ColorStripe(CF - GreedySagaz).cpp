#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 999999999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,k;
string s;
string ans = "";
int change(string a, int atual){
	if(sz(a) == 1){
		ans += a;
		return 0;
	}

	bool at = false;
	for(int i=1;i<sz(a);i+=2){
		int p = 'A';
		for(int j=1;j<=k;j++){
			if(p != a[i]){
				a[i] = p;
				break;
			}
			p++;
		}
	}
	if(atual != -1){
		if(a[sz(a) - 1] == atual){
			int p = 'A';
			for(int i=1;i<=k;i++){
				if(p != atual and p!= a[sz(a)-2]){
					a[sz(a)-1] =  p;
					break;
				}
				p++;
			}
		}
	} 
	ans += a;
	return sz(a)/2;
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	cin >> s;

	if(k == 2){
		string a, b;
		bool at = false;
		for(int i=0;i<sz(s);i++){
			if(!at) a += 'A', at = true;
			else a += 'B', at = false;
		}
		at = true;
		for(int i=0;i<sz(s);i++){
			if(!at) b += 'A', at = true;
			else b += 'B', at = false;
		}

		int ans = 0, ans2 = 0;
		for(int i=0;i<sz(s);i++){
			if(s[i] != a[i]) ans++;
			if(s[i] != b[i]) ans2++;
		}
		if(ans < ans2) {
			cout << ans << endl;
			cout << a << endl;
		} else {
			cout << ans2 << endl;
			cout << b << endl;
		}

	} else {
		int a = 0, b = 0;
		int count = 0;
		while(a < sz(s)){
			string bb = "";
			while(s[b] == s[a]) bb += s[a], b++;
			int atual = -1;
			if(b <= sz(s)-1) atual = s[b];

			count += change(bb, atual);
			
			a = b;
		}

		cout << count << endl;
		cout << ans << endl;
	}


	return 0;
}