#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF (1<<30)
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

//Gerando todos os subconjuntos, backtracking

int at[10000];
int s[10000];

int solve(int i, int n){
	if(i > n){
		for(int j=1;j<=n;j++) if(at[j]) cout << j << " ";
			cout << endl;
	} else {
		at[i] = 1;
		solve(i+1, n);
		at[i] = 0;
		solve(i+1, n);
	}
}

int main(){
	int n;
	cin >> n;
	// solve(1, n);

	return 0;
}