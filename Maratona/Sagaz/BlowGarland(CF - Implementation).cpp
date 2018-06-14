#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 50500
#define MAX 99999999
#define MAXL 20
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
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

string s;
map<int, set<char> > vis;
map<char, int> qt;
vector<char> vec;
int r,y,g,b;

void check(int x){
	int a = x, b = x;
	while(a <= sz(s)){
		if(s[a] == '!') s[a] = s[x], qt[s[x]]++;
		a += 4;
	}

	while(b >= 0){
		if(s[b] == '!') s[b] = s[x], qt[s[x]]++;
		b-=4;
	}
}

void check2(int x){
	int a = x, b = x;
	while(a < sz(s) and a < x + 4) vis[a].insert(s[x]), a++;
	while(b >= 0 and b > x - 4) vis[b].insert(s[x]), b--;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	vec.pb('R'), vec.pb('B'), vec.pb('Y'), vec.pb('G');

	for(int i=0;i<sz(s);i++){
		if(s[i] != '!') check(i);
	}

	for(int i=0;i<sz(s);i++){
		if(s[i] != '!') check2(i);
	}

	for(int i=0;i<sz(s);i++){
		if(s[i] == '!'){
			for(int j=0;j<sz(vec);j++){
				if(vis[i].find(vec[j]) == vis[i].end()){
					s[i] = vec[j];
					qt[s[i]]++;
					check(i);
					check2(i);
					break;
				}
			}
		}
	}

	// cout << s << endl;

	for(int i=0;i<sz(vec);i++){
		cout << qt[vec[i]] << " ";
	} cout << endl;


	return 0;
}