#include <bits/stdc++.h>

using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 10000000
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
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int at[MAX];
	int n;

void crivo(){
	at[1] = 1;

	for(int i=2;i<=n;i++){
		if(!at[i])
		for(int j=2;i*j<=n;j++){
			at[i*j] = 1;
		}
	}

}

int main(){
	cin >> n;

	crivo();
	// for(int i=1;i<=10;i++) cout << at[i] << endl;

	for(int i=2;i<=n;i++){
		if(at[i]==0) cout << i << " ";
	}
	cout << endl;

	return 0;
}