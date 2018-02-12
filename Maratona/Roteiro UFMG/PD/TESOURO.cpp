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
#define MOD 1000000007 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
//ios_base::sync_with_stdio(false);
// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};
 
 
bool subset[100][10000];
 
int main(){
	int x,y,n;
	bool ans;
	int vec[100];
	int sum  = 0;
	int k = 1;
	for(int i=0;i<=100;i++) subset[i][0] = true;
	for(int i=1;i<=10000;i++) subset[0][i] = false;
 
	while(1){
		ss(x,y), s(n);
		if(x == 0 and y == 0 and n == 0) break;
		if(x > y) swap(x,y);
		sum = 0;
		for(int i=0;i<n;i++) s(vec[i]), sum += vec[i];
		subset[n][0] = true;
		if(k > 1) printf("\n");
		ans = false;
		// cout << "Sum : " << sum << endl;
		int tot = sum;
		if(x == y){
			sum/=2;
		} else {
			if(x + tot < y){
			printf ("Teste %d\n", k++);
			printf ("N\n");
				continue;
			} else {
				sum = (tot + y - x)/2;
			}
		}
 
		for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j < vec[i-1]) subset[i][j] = subset[i-1][j];
			else if(j >= vec[i-1]) subset[i][j] = subset[i-1][j] or subset[i-1][j-vec[i-1]];
			
			if(subset[i][j]){
				// cout << "J : " << j << endl;
				if((x + j == y + tot - j or (x + (tot - j) == y + j)) and j + (tot - j) == tot){
					ans = true;
					break;
				}
			}
		}
		if(ans) break;
	}
 
 
		// else cout << "N" << endl;
		printf ("Teste %d\n", k);
		if(ans) printf ("S\n");
		else printf("N\n");
		k++;
	}
 
 
 
	return 0;
} 