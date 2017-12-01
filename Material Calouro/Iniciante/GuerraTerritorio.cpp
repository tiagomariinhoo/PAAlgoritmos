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

//Guerra por territorio

int main(){
	int n;
	cin >> n;
	int vec[100005];
	int sum = 0;
	for(int i=0;i<n;i++) s(vec[i]), sum += vec[i];

	int ans = 0;
	for(int i=0;i<n;i++){
		ans += vec[i];
		if(ans == sum/2){
			cout << i+1 << endl;
			return 0;
		}
	}



	return 0;
}