#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF 1000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
/*
	Achar o numero minimo e maximo de tamanho n e soma dos caracteres, m.
*/
bool solve(int a, int b){return b>=0 && b <= 9*a;} 

int main(){
	int m,s;
	cin >> m >> s;
	string minn;
	int sum = s;
	for(int i=0;i<m;i++){
		for(int j=0;j<10;j++){
			if((i > 0 or j > 0 or (m == 1 and j == 0)) and solve(m - i - 1, sum - j)){
				minn += char('0' + j);
				sum -= j;
				break;
			}
		}
	}
	string maxx;
	int sum2 = s;
	for(int i=0;i<m;i++){
		for(int j=9;j>=0;j--){
			if((i > 0 or j > 0 or (m == 1 and j == 0)) and solve(m - i - 1, sum2 - j)){
				maxx += char('0' + j);
				sum2 -= j;
				break;
			}
		}
	}

	if(s == 0 and m > 1){
		cout << -1 << " " << -1 << endl;
		return 0;
	}

	if(sum==0) cout << minn << " ";
	else cout << -1 << " ";
	if(sum2==0) cout << maxx << endl;
	else{
		if(sum==0) cout << minn << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}