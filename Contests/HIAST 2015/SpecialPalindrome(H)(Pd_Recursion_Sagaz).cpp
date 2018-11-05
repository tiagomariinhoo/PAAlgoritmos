#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20

int aux;
lli pd[251][251];

lli solve(int last, int sum){
	lli &ans = pd[last][sum];
	if(ans != -1) return ans;
	if(sum > aux) return ans = 0;
	else if(sum == aux) return ans = 1;
	ans = 0;
	for(int i=last;i<=aux;i++){
		if(sum + i == aux) ans++;
		if(sum + i*2 > aux) continue;
		ans += solve(i, sum+(i*2));
	}
	return ans;
}

lli ans[251];

int main(){

	for(int i=1;i<=250;i++){
		// cout << "i : " << i << endl;
		aux = i;
		memset(pd, -1, sizeof pd);
		ans[i] = solve(0, 0);
		// cout << ans[i] << endl;
	}
    memset(pd, -1, sizeof pd);
    while(1){
        cin >> aux;
        if(!aux) break;
        cout << ans[aux] << endl;
    }


    return 0;
}