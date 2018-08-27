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

/*
	Dado valor pra cada letra do alfabeto
	Achar número de substrings que comecem e terminem com a mesma letra
	e a soma das letras de dentro dê 0

*/

vector<int> pos[30];
string s;
lli pre[100001];
int n;
lli value[100001];
int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for(int i=0;i<26;i++) cin >> value[i];

  cin >> s;
	for(int i=0;i<sz(s);i++){
		pre[i+1] = pre[i] + value[s[i] - 'a'];
		pos[s[i] - 'a'].pb(i);
	}

	lli ans = 0;
	for(int i=0;i<26;i++){
		map<lli, int> sum;
		char aux = i+'a';
		// cout << "Aux : " << aux << endl;
		for(int j=0;j<sz(pos[i]);j++){
			int atual = pos[i][j];
			ans += sum[pre[atual]];
			// cout << pre[atual-1] << a" - " << pre[atual] << endl;
			sum[pre[atual+1]]++;
		}
	}

	cout << ans << endl;

  return 0;
}