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
 
int bit[1003][1003];
int n;

int sum(int x, int y){
	// cout << "X : " << x << " - " << "Y : " << y << endl;
	int ans = 0;
	for(int i=x;i>0;i-=i&-i)
		for(int j=y;j>0;j-=j&-j){
			// cout << i << " - " << j << endl;
			// cout << "Bit i j : " << bit[i][j] << endl;
			ans = max(ans, bit[i][j]);
		}

	return ans;
}

void update(int x, int y, int d){
	// cout << " ---- Update ---- " << endl;
	// cout << x << " - " << y << " - " << d << endl;
	for(int i=x;i<=1002;i+=i&-i)
		for(int j=y;j<=1002;j+=j&-j){
			// cout << i << " - " << j << " - " << bit[i][j] << endl;
			bit[i][j] = max(d,bit[i][j]);
		}
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while(t--){
		// cout << "- -- - - - - - - " << endl;
		memset(bit, 0, sizeof bit);
		int ans = 0;
		cin >> n;
		for(int i=0;i<n;i++){
			int a,b;
			cin >> a >> b;
			int aa = 0;
			aa = sum(a,b) + 1;
			ans = max(ans, aa);			
			update(a,b,aa);
		}
		cout << ans << endl;
	}

	return 0;
}