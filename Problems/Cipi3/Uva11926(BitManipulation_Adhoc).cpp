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

int vec[1000011];
int n, m;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
 	while(1){
 		cin >> n >> m;
 		if(!n and !m) break;

 		bool at = false;
 		memset(vec, 0, sizeof vec);
 		for(int i=0;i<n;i++){
 			int a,b;
 			cin >> a >> b;
 			for(int j=a;j<b;j++){
 				if(vec[j]) at = true;
 				else vec[j] = 1;
 			}
 		}

 		for(int i=0;i<m;i++){
 			int a, b, c;
 			cin >> a >> b >> c;
 			while(1){

 				for(int j=a;j<b;j++){
 					if(vec[j]) at = true;
 					else vec[j] = 1;
 				}
 				if(b >= 1000000) break;
 				a+=c;
 				b+=c;
 				a = min(a, 1000000), b = min(b, 1000000);
 			}
 		}


 		if(at) cout << "CONFLICT" << endl;
 		else cout << "NO CONFLICT" << endl;
 	}

	return 0;
}
