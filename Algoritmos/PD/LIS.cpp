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
// ios_base::sync_with_stdio(false);

int main(){
	int n;
	vi vec,LIS;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
		LIS.pb(1);
	}
	int ans = 1;
	sort(vec.begin(), vec.end());
	 for (i = 0; i < n; i++ )
        lis[i] = 1;

 for (i = 1; i < n; i++ )
        for (j = 0; j < i; j++ ) 
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

 for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];

	cout << ans << endl;

	return 0;
}