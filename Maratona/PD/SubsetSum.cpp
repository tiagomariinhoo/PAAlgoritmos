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
int vec[105];
int n,d;
int valor[105];
int sum;

bool subSum(int sum1, int sum2){
	if(sum == d) return true;
	bool subset[n+1][sum+1];
	for(int i=0;i<=n;i++) subset[i][0] = true;

	for(int i=1;i<=sum;i++) subset[0][i] = false;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j < valor[i-1]) subset[i][j] = subset[i-1][j];
			if(j >= valor[i-1]) subset[i][j] = subset[i-1][j] or subset[i-1][j-valor[i-1]];
		}
	}

	for(int i=0;i<=n;i++)
		for(int j=1;j<=sum;j++)
			if(subset[i][j])
				if(abs(j - (sum - j)) == d) return true;
				
	return false;
}



int main(){

	int a, i=0;
	
	while(s(a)!=EOF){
		vec[i++] = a;
	}
	d = vec[i-1];
	n = i-1;

	for(int i=0;i<n;i++) sum += vec[i], valor[i] = vec[i];
	int sum2 = 0;

	bool at = subSum(0,0);
	if(at) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}