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

//Iniciante Geometria
//Jogo de varetas https://www.urionlinejudge.com.br/judge/pt/problems/view/1366

int main(){
	int n;
	while(1){
		cin >> n;
		if(n==0) break;
		int ans = 0,a,b;
		for(int i=0;i<n;i++) ss(a,b), ans+=b/2;
		cout << ans / 2 << endl;
	}


	return 0;
}