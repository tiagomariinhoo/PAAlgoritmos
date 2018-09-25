#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
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
typedef vector<lli> vi;
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

#define MAXN 100001

string doSum(string a, string b){
	if(sz(a) < sz(b)) swap(a, b);

	int j = sz(a)-1;
	for(int i=sz(b)-1;i>=0;i--,j--) a[j] += (b[i] - '0');

	for(int i=sz(a)-1;i>0;i--){
		if(a[i] > '9'){
			int d = a[i] - '0';
			a[i-1] = ((a[i-1]-'0') + d/10) + '0';
			a[i] = (d%10) + '0';
		}
	}

	if(a[0] > '9'){
		string k;
		k += a[0];
		a[0] = ((a[0] - '0')%10) + '0';
		k[0] = ((k[0] - '0')/10) + '0';
		a = k+a;
	}
	return a;
}

int main(){ 
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
  	string s;
 		cin >> s;

 		string next;
 		if(s[0] <= '8'){
 			next += s[0]+1;
 			for(int i=0;i<sz(s)-1;i++) next += '0';
 		} else {
 			next += '1';
 			for(int i=0;i<sz(s);i++) next += '0';
 		}

 		s = doSum(s, "1");

 		bool at = true;
 		bool foi = false;
 		while(1){
 			int a = 0,b = sz(s) - 1;
 			int resto = 0;
 			while(a < b){
 				if(resto){
 					if(s[b] == '9') s[b] = '0';
 					else s[b]++, resto = 0;
 				}

 				if(s[b] < s[a]){
 					s[b] = s[a];
 				} else if(s[b] > s[a]){
 					s[b] = s[a];
 					resto = 1;
 					for(int i=b-1;i>=0;i--){
 						if(!resto) break;
 						if(s[i] == '9') s[i] = '0';
 						else s[i]++, resto = 0;
 						if(!i and resto) at = false;
 					}
 				} 
 				a++, b--;
 			}
 			if(resto and !at and !foi) s = next, at = true, foi = true;
 			string aux = s;
 			reverse(aux.begin(), aux.end());

 			if(aux == s){
 				cout << s << endl;
 				break;
 			}

 		}

  }

   return 0; 
} 