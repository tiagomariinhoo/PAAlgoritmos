/*
	Questão 189 / A, DP Importante
	Dado um N, quantas vezes consigo dividir tal que
	o tamanho dos divididos tenham tamanho a,b ou c

*/


#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define MAX 11000
#define MAXN 120
#define MIN -2000000
#define INF 0x3f3f3f3f
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> ii;
typedef pair<int, ii > iii;
#define F first
#define S second
int n, aux;

int main(){
	cin >> n;
	aux = n;
	vi vec;
	for(int i = 0 ; i < 3; i++){
		int a;
			cin >> a;
				vec.pb(a);
	}
	int i = 0, j, k;

	sort(vec.begin(),vec.end());
	int ans = 0;

	while(vec[0]*i <= n ){
		if(vec[0]*i == n) ans = max(ans, i);
		if(n%vec[0]==0) {
			ans = max(ans, n/vec[0]);
			break;
		}
		else if (vec[0]*i < n){
			j = 0;
			while(vec[0]*i + vec[1]*j <= n){
				k = 0;
				if(vec[0]*i + vec[1]*j == n) ans = max(ans, i + j);
				else if (vec[0]*i + vec[1]*j <= n){
					while(vec[0]*i + vec[1]*j + vec[2]*k < n) k++;
					if(vec[0]*i + vec[1]*j + vec[2]*k == n) ans = max(ans, i + j + k);
				}
			j++;
			}
		}
		i++;
	}
		if(vec[0]*i == n) ans = max(ans, i);

	cout << ans << endl;

	return 0;
}