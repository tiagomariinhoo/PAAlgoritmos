#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
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
#define d 256
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {0, 1};

lli pd[20][2][200];


lli solve(int pos, int can, lli sum, vi b){
	if(pos == sz(b))
		return sum;


	if(pd[pos][can][sum] != -1) return pd[pos][can][sum];

	int atual = can ? (b[pos]) : 9;

	lli aux = 0;
	
	for(int i=0;i<=atual;i++){
		if(i == b[pos]) aux += solve(pos+1, can, sum + i, b);
		else aux += solve(pos+1, 0, sum+i, b);
	}

	return pd[pos][can][sum] = aux;
}

vi vec, vec2;
void toint(lli a, lli b){
	a--;
	a = max(a, 0LL);
	vec.pb(a%10);
	a/=10;
	while(a > 0){
		vec.pb(a%10);
		a/=10;
	} 

	vec2.pb(b%10);
	b/=10;
	while(b > 0){
		vec2.pb(b%10);
		b/=10;
	}

	reverse(vec.begin(), vec.end());
	reverse(vec2.begin(), vec2.end());
}
lli a, b;
	
lli resp(lli atual){
	lli soma = atual%10;
	atual /= 10;
	while(atual>0){
		soma += atual%10;
		atual/=10;
	}
	return soma;
}

void oraculo(){
	lli sum = 0;
	for(int i=0;i<=a-1;i++){
		sum += resp(i);
	}
	cout << "Oraculo! : " << endl;
	cout << a << " - " << sum << endl;
	sum = 0;
	for(int i=0;i<=b;i++){
		sum += resp(i);
	}
	cout << b << " - " << sum << endl;
	cout << " --- " << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while(cin >> a >> b){
		// if(a == -1 and b == -1) break;
		vec.clear(), vec2.clear();
		toint(a, b);
		// for(int i=0;i<sz(vec);i++) cout << vec[i] << " ";
		// 	cout << endl;
		// for(int i=0;i<sz(vec2);i++) cout << vec2[i] << " ";
		// 	cout << endl;
		// oraculo();
		memset(pd, -1, sizeof pd);
		lli aa = solve(0, 1, 0, vec2);
		// lli aa = solve(0, 1, 0, 0, vec2);
		memset(pd, -1, sizeof pd);
		// lli bb = solve(0, 1, 0, 0, vec);
		lli bb = solve(0, 1, 0 , vec);
		// cout << aa << " - " << bb << endl;
		cout << aa - bb << endl;
		// cout << solve(0, 1, 0, vec2) - solve(0, 1, 0, vec) << endl;
		// cout << solve(0, 1, 0, vec2) << endl;


	}

	return 0;
}