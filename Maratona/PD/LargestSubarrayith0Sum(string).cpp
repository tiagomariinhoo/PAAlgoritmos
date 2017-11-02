#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100001
#define MIN -2000000
#define INF 90000000
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

int n;
string s;
int aa[100001];

/*
	Dado uma string com 01010101
	Achar a maior substring que tem o mesmo numeros de 0 e 1
	Basta usar 0 = -1 e 1 = 1 e achar o maior subarray que a soma é 0
*/

int solve(){
	int sum = 0 , ans = 0;
	map<int, int> maps;
	for(int i=0;i<n;i++){
		sum += aa[i];
		if(sum == 0) ans=i+1;
		if(maps.find(sum)!=maps.end()) ans = max(ans, i - maps[sum]);
		else maps[sum]=i;
	}
	return ans;
}

int main(){
	cin >> n;
	cin >> s;
	for(int i=0;i<n;i++){
		if(s[i]=='1') aa[i] = 1;
		else aa[i] = -1;
	}
	cout << solve() << endl;
}