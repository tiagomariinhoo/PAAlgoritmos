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
#define MOD 1e9 + 9
#define MOD2 1e9 + 7
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
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
// #define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};
 
 
 
int n,k;
string s;
 
// lli compHash(){
// 	const int p = 31;
//     const int m = 1e9 + 9;
//     long long hash_value = 0;
//     long long p_pow = 1;
//     for (char c : s) {
//         hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
//         p_pow = (p_pow * p) % m;
//     }
//     return hash_value;
// }
 
void solve(){
	   int n = s.size();
 
    const lli p = 31;
    const lli m = MOD, mm = MOD2;
    vector<long long> p_pow(n), p_pow2(n);
    p_pow[0] = 1;
    p_pow2[0] = 1;
    for (lli i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m, p_pow2[i] = (p_pow2[i-1]*p)%mm;
 
    vector<long long> h(n + 1, 0), hh(n + 1, 0);
    for (lli i = 0; i < n; i++){
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    	hh[i+1] = (hh[i] + (s[i] - 'a' + 1) * p_pow2[i]) %mm;
    }
 
    lli cnt = 0;
    for (lli l = k; l <= k; l++) {
    	set<pair<lli,lli>>vec;
    	set<lli> ans;
        for (lli i = 0; i <= n - l; i++) {
            lli cur_h = (h[i + l] + m - h[i]) % m;
            lli cur_h2 = (hh[i+l] + mm - hh[i])%mm;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            cur_h2 = (cur_h2 * p_pow2[n-i-1])%mm;
            // vec.pb({cur_h, cur_h2});
            vec.insert({cur_h, cur_h2});
        }
        // int ans = 0;
        // cout << min(sz(hs), sz(hs2)) << endl;
        // for(int i=0;i<sz(vec);i++) if(vec[i].F == vec[i].S) ans.insert(vec[i].F);
        // cout << sz(ans) << endl;
        cout << sz(vec) << endl;
    }
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cin >> s;
 
		// cout << compHash() << endl;
		solve();
	}
 
	return 0;
} 