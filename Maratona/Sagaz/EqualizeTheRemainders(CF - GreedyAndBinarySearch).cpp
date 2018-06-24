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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
vector<int> vec;
int qt[200001];
queue<lli> sum[200001];

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		lli a;
		cin >> a;
		vec.pb(a);
		qt[a%m]++;
	}

	set<int> aa, bb;
	for(int i=0;i<m;i++){
		if(qt[i] == (n/m)) continue;
		else if(qt[i] > (n/m)) aa.insert(i);
		else bb.insert(i);
	}
	lli ans = 0;
	for(auto i : aa){
		while(qt[i] > (n/m)){
			int j, k;
			int aux = 0, ansi;
			set<int>::iterator it = bb.lower_bound(i);
			if(it == bb.end()){
				j = *(--it);
				k = *bb.begin();

				if(m - i + j < m - i + k){
					ansi = j;
					aux = m - i + j;
				} else {	
					ansi = k;
					aux = m - i + k;
				}
			} else {
				if(it == bb.begin()){

					aux += (*bb.begin()) - i;
					ansi = *bb.begin();
				} else {
					k = *(it);
					j = *(--it);
					if(k - i < (m - i + j)){
						ansi = k;
						aux  = k - i;
					} else {
						ansi = j;
						aux = m - i + j;
					}
				}
			}

			ans += aux;
			qt[i]--;
			qt[ansi]++;
			if(qt[ansi] == n/m) bb.erase(ansi);
			sum[i].push(aux);
		}
	}

	cout << ans << endl;
	for(int i=0;i<sz(vec);i++){
		int a = vec[i]%m;
		if(sz(sum[a])){
			cout << vec[i] + sum[a].front() << " ";
			sum[a].pop();
		} else {	
			cout << vec[i] << " ";
		}
	} cout << endl;

	return 0;
}