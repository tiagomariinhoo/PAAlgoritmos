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

vector<lli> vec;
lli ans2 = 0;
lli teste;
void sim(int pos, int x){
	lli vec2[17];
	memset(vec2, 0, sizeof vec2);
	for(int i=0;i<14;i++){
		vec2[i+1] = vec[i];
	}
	vec2[pos+1] = 0;
	// cout << " -------- " << endl;
	// cout << "Teste : " << endl;
	// cout << x << " - " << pos << endl;
	int xx = x;
	int i = pos+2;
	if(i == 15) i = 1;
	while(x > 0){
		vec2[i]++;

		i++;
		if(i == 15) i = 1;
		x--;
	}
	lli sum = 0;
	for(int i=1;i<=14;i++){

		// if(xx == 150 and pos == 12) cout << i << " - " << vec2[i] << endl;
		if(vec2[i]%2==0) sum += vec2[i];
	}



	teste = max(teste, sum);
	// cout << "Ans : " << sum << endl;
	// cout << " --------- " << endl;
}

void check(int pos, int x){
	lli vec2[16];

	for(int i=0;i<14;i++){
		vec2[i+1] = vec[i];
	}
	vec2[pos+1] = 0;
	int i = pos+2;

	int atual = x;
	if(i == 15) i = 1;

	// lli resto = atual >= (14) ? atual%(14) : 0;
	// lli div = atual >= (14) ? atual/(14) : 1;
	lli resto = atual%14;
	lli div = atual/14;
	lli xx = x;
	// cout << "Resposta: " << endl;
	// 	cout << x << " -- " << pos << endl;
	// 	cout << div << " - " << resto << endl;

		if(div == 0){
			while(resto > 0){
				vec2[i]++;
				resto--;
				i++;
				if(i == 15) i = 1;
			}
		} else {
			while(xx > div){
				vec2[i] += div;
				xx -= div;
				i++;
				if(i == 15) i = 1;
			}

			while(resto > 0){
				vec2[i]++;
				resto--;
				i++;
				if(i == 15) i = 1;
			}
		}


	// if(div == 1){
	// 	while(xx > 0){
	// 		vec2[i] += div;
	// 		xx -= div;
	// 		i++;
	// 		if(i == 15) i = 1;
	// 	}

	// 	while(resto > 0){
	// 		vec2[i]++;
	// 		resto--;
	// 		i++;
	// 		if(i==15) i = 1;
	// 	}

	// } else {
	// 	while(xx > 0){
	// 		vec2[i] += div;
	// 		xx -= div;
	// 		i++; 
	// 		if(i == 15) i = 1;
	// 	}

	// 	while(resto > 0){
	// 		vec2[i]++;

	// 		resto--;
	// 		i++;
	// 		if(i == 15) i = 1;
	// 	}
	// }
		
		lli sum = 0;
		for(int i=1;i<=14;i++){
			if(vec2[i]%2==0) sum += vec2[i];
		}

		// if(x == 150 and pos == 12){
		// 	for(int i=1;i<=14;i++){
		// 		cout << i << " - " << vec2[i] << endl;
		// 	}
		// }
		// cout << "Sum : " << sum << endl;
		ans2 = max(sum, ans2);
}

int main(){
	ios_base::sync_with_stdio(false);
	for(int i=0;i<14;i++){
		int a;
		cin >> a;
		vec.pb(a);
	}

	for(int i=0;i<sz(vec);i++){
		int a = vec[i];
		// sim(i, a);
		check(i, a);
	}

	cout << ans2 << endl;
	// cout << "Teste : " << teste << endl;
	return 0;
}