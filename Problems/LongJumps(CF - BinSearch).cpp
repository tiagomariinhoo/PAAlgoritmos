#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,l,x,y;
vi vec;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> x >> y;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	vi ans;
	vi aux;
	bool at = false;
	int ans1 = 0;
	for(int i=0;i<sz(vec);i++){
		if(vec[i] == x){
			ans1 = x;
			at = true;
		}
		else if(vec[i] > x){
			if(binary_search(vec.begin(), vec.end(), vec[i] - x)){
				ans1 = vec[i] - x;
				at = true;
				break;
			} else{
				aux.pb(vec[i] - x);
				if(vec[i] + x <= l) aux.pb(vec[i] + x);
			}
		} else {
			if(vec[i] + x <= l) aux.pb(vec[i] + x);
		}
	}
	vi aux2;
	bool at2 = false;
	int ans2 = 0;
	for(int i=0;i<sz(vec);i++){
		if(vec[i] == y){
			ans2 = y;
			at2 = true;
		} else if(vec[i] > y){
			if(binary_search(vec.begin(), vec.end(), vec[i] - y)){
				ans2 = vec[i] - y;
				at2 = true;
				break;
			} else {
				aux2.pb(vec[i] - y);
				if(vec[i] + y <= l) aux2.pb(vec[i] + y);
			} 
		} else {
			if(vec[i] + y <= l) aux2.pb(vec[i] + y);
		}
	}

	if(at and at2) cout << 0 << endl;
	else if(!at and at2){
		cout << 1 << endl;
		cout << aux[0] << endl;
	} else if(at and !at2){
		cout << 1 << endl;
		cout << aux2[0] << endl;
	} else if(!at and !at2){

		// for(int i=0;i<sz(aux);i++) cout << aux[i] << " ";
		// 	cout << endl;
		// for(int i=0;i<sz(aux2);i++) cout << aux2[i] << " ";
		// 	cout << endl;

		sort(aux.begin(), aux.end());
		sort(aux2.begin(), aux2.end());
		
		for(int i=0;i<sz(aux);i++){
			if(binary_search(aux2.begin(), aux2.end(), aux[i])){
				cout << 1 << endl;
				cout << aux[i] << endl;
				return 0;
			}
		}
		cout << 2 << endl;
		cout << aux[0] << " " << aux2[0] << endl;
	}	

	return 0;
}