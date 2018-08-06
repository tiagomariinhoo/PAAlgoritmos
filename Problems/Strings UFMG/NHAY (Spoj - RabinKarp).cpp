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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

#define d 256
vector<int> ans;

void rabinKarp(string txt, string pat, int q){
	int M = sz(pat);
	int N = sz(txt);
	int p = 0, t = 0, h = 1, j;

	if(M > N) return ;

	for(int i=0;i<M-1;i++){
		h = (h*d)%q;
	}

	for(int i=0;i<M;i++){
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}

	for(int i=0;i<=N-M;i++){
		if(p == t){
			for(j=0;j<M;j++){
				if(txt[i+j] != pat[j]) break;
			}

			if(j == M)
				ans.pb(i);			
		}

		if(i < (N - M)){
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			if(t < 0) t += q;
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	while(cin >> n){
		string a,b;
		cin >> a >> b;

		rabinKarp(b, a, 541);

		if(!sz(ans)) cout << endl;
		else {
			for(int i=0;i<sz(ans);i++) cout << ans[i] << endl;
		}	
		ans.clear();
	}


	return 0;
}