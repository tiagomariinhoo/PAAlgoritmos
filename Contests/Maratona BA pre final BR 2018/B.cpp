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
#define MOD2 998244353

string s;
string aux;

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  cin >> aux;

  int ans = 0;
  set<char> has;
  for(int i=0;i<sz(aux);i++) has.insert(aux[i]);

  for(int i=0;i<sz(s) - sz(aux) + 1;i++){
  	set<char> qt;
  	for(int j=0;j<sz(aux);j++) qt.insert(s[i+j]);
  	if(sz(qt) > 2) continue;

  	map<char, char> vis, vis2;
  	bool at = false, at2 = false;
  	// cout << "I : " << i << endl;
  	for(int j='a';j<='z';j++) vis[j] = '-', vis2[j] = '-';
  		vis['1'] = '-', vis['0'] = '-';
  	for(int j=0;j<sz(aux);j++){
  		// cout << aux[j] << " - " << vis[aux[j]] << endl;
  		if(vis[aux[j]] == '-') vis[aux[j]] = s[i+j];
  		else if(vis[aux[j]] != s[i+j]) at = true;
  	}

  	for(int j='a';j<='z';j++) vis[j] = '-', vis2[j] = '-';
  		vis['1'] = '-', vis['0'] = '-';
  	int k = 0;
  	for(int j=sz(aux)-1;j>=0;j--){
  		if(vis[aux[j]] == '-') vis[aux[j]] = s[k+i];
  		else if(vis[aux[j]] != s[k+i]) at2 = true;
  		k++;
  	}
  	if(!at or !at2) ans++;
  }

  cout << ans << endl;

  return 0;
}