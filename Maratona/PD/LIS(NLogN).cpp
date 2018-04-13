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

//SEM REPETIR NUMEROS : 1 4 4 5, : 3

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

//PARA NUMEROS REPETIDOS : 1 4 4 5. : 4

multiset<int> s;
multiset<int> ::iterator it;

int main(){
	int n;
	cin >> n;
	vi vec;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	for(int i=0;i<sz(vec);i++){
		s.insert(vec[i]);
		it = s.upper_bound(vec[i]);

		for(auto j : s) cout << j << " ";
			cout << endl;

		if(it != s.end()) s.erase(it);
	}
	
	for(auto j  : s) cout << j << " ";
		cout << endl;

	cout << sz(s) << endl;


	return 0;
}