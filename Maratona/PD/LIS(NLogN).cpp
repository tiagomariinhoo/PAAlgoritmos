#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (1 << 30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<lli, lli> iil;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

set<int> st;
set<int>::iterator it;

int main(){
	st.clear();
	int n;
	int vec[50];
	cin >> n;
	for(int i=0;i<n;i++) cin >> vec[i];

	for(int i=0;i<n;i++){
		st.insert(vec[i]);
		it = st.find(vec[i]);
		it++; if(it!=st.end()) st.erase(it);
	}

	cout << st.size() << endl;

	return 0;
}