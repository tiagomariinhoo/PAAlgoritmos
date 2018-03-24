#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 3000000
#define MAXL 20
#define MIN -2000000
#define INF (500000000)
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

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	int line = 1000000000;
	bool at = false;
	int col = 1, atual = vec[0], maxi = vec[0];
	int aa = 0, bb = 0, dif = -1;

	for(int i=1;i<sz(vec);i++){
		if(vec[i] == atual){
			cout << "NO" << endl;
			return 0;
		}

		if(vec[i] == atual + 1){
			if(dif == -1){
				if(vec[i] > maxi) maxi = vec[i], col++;
			}
			
		} else if(vec[i] != atual - 1){
			if(dif == -1){
				dif = abs(vec[i] - atual);
				if(dif < col){
					cout << "NO" << endl;
					return 0;
				}
			} else {
				if(abs(vec[i] - atual) != dif){
					cout << "NO" << endl;
					return 0;
				}
			}
		}

		atual = vec[i];
		col = max(col, dif);
	}

	if(dif == -1) col = 1;
	else{
		for(int i=1;i<sz(vec);i++){
			if(abs(vec[i] - vec[i-1]) == 1 and min(vec[i], vec[i-1])%dif == 0){
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	cout << line << " " << col << endl;


	return 0;
}