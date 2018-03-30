#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF 191919
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
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n;
vi vec;
map<int, int> qt;

bool comp(int a, int b){ return a > b; }

bool check(vi aux){
	for(int i=0;i<sz(aux);i++){
		int dist = sz(aux) - i - 1;
		if(dist == aux[i]) return false;
	}
	return true;
}

vi dim(vi aux){
	for(int i=0;i<sz(aux);i++){
		for(auto j : qt){
			int a = j.F;
			int qtt = j.S;
			int dist = sz(aux) - i - 1;
			// cout << a << " - " << aux[i] << " - " << dist << endl;
			if(qtt > 0){
				if(dist <= a){
					qt[aux[i]]++;
					aux[i] = a;
					qt[a]--;
					// cout << aux[i] << " - " << a << endl;
					break;
				}
			}
		}
	}
	return aux;
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		qt[a]++;
		vec.pb(a);
	}

	sort(vec.begin(), vec.end(), comp);

	int ans = 0;
	for(int i=0;i<sz(vec);i++){
		if(qt[vec[i]] > 0){
			vi aux;
			aux.pb(vec[i]);
			int a = i+1;
			while(check(aux) and a < sz(vec)){
				aux.pb(vec[a]);
				a++;
			}
			
			for(auto j : aux) qt[j]--;

			aux = dim(aux);

			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}