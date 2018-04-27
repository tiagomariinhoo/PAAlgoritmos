#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 999999999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli unsigned long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

vector<ii> vec, aux;
int xa, xb, xc, xd, ya, yb, yc, yd;
long double ans = 360;

/*
	DADO N PARES DE COORDENADAS
	Achar o angulo minimo que cubra todas as coordenadas
	comp: ordenação clockwise coordenadas
	https://stackoverflow.com/questions/6989100/sort-points-in-clockwise-order?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa

*/

bool comp(ii &a, ii &b){
	if(a.F >= 0 and b.F < 0) return true;
	if(a.F < 0 and b.F >= 0) return false;
	if(a.F == 0 and b.F == 0){
		if(a.S >= 0 or b.S >= 0) return a.S > b.S;
		return b.S > a.S;
	}
	int det = (a.F * b.S) - (b.F * a.S);
	if(det < 0) return true;
	if(det > 0) return false;
	int d1 = (a.F * a.F) + (a.S*a.S);
	int d2 = (b.F * b.F) + (b.S*b.S);
	return d1 > d2;
}

long double takeAngle(int x, int y, int xx, int yy){
	
	long double aa = x*xx + y*yy;
	long double bb = x*yy - y*xx;
	long double angle = atan2(bb, aa);
	return angle*180/M_PI;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 1){
		cout << "0.0000000" << endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		aux.pb({a,b});
	}

	sort(aux.begin(), aux.end(), comp);
	
	ans = 0;
	long double aux2 = takeAngle(aux[sz(aux) - 1].F, aux[sz(aux) - 1].S, aux[0].F, aux[0].S);
	aux2 = abs(aux2);
	long double maxi = aux2;

	for(int i=0;i<sz(aux)-1;i++){
		long double aa = takeAngle(aux[i].F, aux[i].S, aux[i+1].F, aux[i+1].S);
		aa = abs(aa);

		maxi = max(maxi, aa);
		aux2 += aa;
	}
	ans = aux2 - maxi;
	printf("%.10Lf\n", abs(ans));

	return 0;
}