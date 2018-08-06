#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 10000001
#define MIN -2000000
#define INF (int)1e9
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
//ios_base::sync_with_stdio(false);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

/*
	Dado as quantidades e preços, maximiza a quantidade
*/

string ss;
lli s,b,c;
lli ns,nb,nc;
lli ps,pb,pc;
lli r;

int main(){
ios_base::sync_with_stdio(false);

	cin >> ss;
	for(int i=0;i<sz(ss);i++){
		if(ss[i] == 'S') s++;
		else if(ss[i]=='B') b++;
		else c++;
	}

	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	if(s == 0) ps = 0;
	if(b == 0) pb = 0;
	if(c == 0) pc = 0;
	lli com = 0, fim = 2000000000000;
	lli ans = 0;
	while(com < fim){
		lli aux = (com + fim) >> 1;

		lli qtb = (((b*aux)-nb)) * pb;
		lli qts = (((s*aux)-ns)) * ps;
		lli qtc = (((c*aux)-nc)) * pc;
		// cout << "Aux : " << aux << endl;
		// cout << qtb << " - " << qts << " - " << qtc << endl;
		lli zero = 0;
		qtb = max(qtb, zero);
		qts = max(qts, zero);
		qtc = max(qtc, zero);
		// if(qtb < 0 or qts < 0 or qtc < 0){
		// 	aux = (aux/2) + aux;
		// 	continue;
		// }
		// if(qtb + qts + qtc <= r){
		// 	ans = max(ans, aux);
		// } 
			
		
		if(qtb + qts + qtc > r) fim = aux;
		else{
		ans = max(ans, aux);
		com = aux + 1;	
		} 
	}
	cout << ans << endl;

	return 0;
}