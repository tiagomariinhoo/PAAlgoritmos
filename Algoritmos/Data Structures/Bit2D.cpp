#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 10000001
#define MIN -2000000
#define INF (int)1e9
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define MOD 1000000007 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
//ios_base::sync_with_stdio(false);
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

int bit[1500][1500];
int n,m;

int sum(int x, int y){
	int ans = 0;
	for(int i=x;i>0;i-=i&-i)
		for(int j=y;j>0;j-=j&-j) ans += bit[i][j];

	return ans;
}

void update(int x, int y, int d){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j) bit[i][j] += d;
}

int main(){
	ios_base::sync_with_stdio(false);
	n = 5, m = 5;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++) update(i,j,i+1);


	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++) cout << bit[i][j] << " ";
		cout << endl;
	}

	cout << sum(1,5) << endl;
	//Para pegar a soma apenas de uma linha inteira : sum(2,5) - sum(1,5)

	return 0;
}