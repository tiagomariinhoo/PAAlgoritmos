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
typedef vector<int> vi;
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

int a,b,c,d;
char ans[51][51];
map<int, char> alf;
map<char, int > qt;

bool test(int x, int y, char aa){
	for(int i=0;i<4;i++){
		int xx = x + dx[i];
		int yy = y + dy[i];
		if(xx >= 0 and xx < 50 and yy >= 0 and yy < 50){
			if(ans[xx][yy] == aa) return false;
		}
	}
	return true;
}

void fill(char aa){

	if(aa == 'A'){
		for(int i=14;i<=23;i+=2){
			for(int j=1;j<=49;j+=2){
				if(!qt[aa]) return;
				if(test(i, j, aa)){
					ans[i][j] = aa;
					qt[aa]--;
				}
			}
		}
	} else if(aa == 'B'){
		for(int i=26;i<=35;i+=2){
			for(int j=1;j<=49;j+=2){
				if(test(i, j, aa)){
					ans[i][j] = aa;
					qt[aa]--;
					if(!qt[aa]) return;
				}
			}
		}
	} else if(aa == 'C'){
		for(int i=38;i<=47;i+=2){
			for(int j=1;j<=49;j+=2){
				if(test(i, j, aa)){
					ans[i][j] = aa;
					qt[aa]--;
					if(!qt[aa]) return;
				}
			}
		}
	} else if(aa == 'D'){
		for(int i=2;i<=11;i+=2){
			for(int j=1;j<=49;j+=2){
				if(test(i, j, aa)){
					ans[i][j] = aa;
					qt[aa]--;
					if(!qt[aa]) return;
				}
			}
		}
	}

}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c >> d;
	a--, b--, c--, d--;

	alf[1] = 'A', alf[2] = 'B', alf[3] = 'C', alf[4] = 'D';	
	qt['A'] = a, qt['B'] = b, qt['C'] = c, qt['D'] = d;
	int aa = a;

	for(int i=1;i<=12;i++){
		for(int j=0;j<=50;j++){
			ans[i][j] = 'A';
		}		
	}

	for(int i=13;i<=24;i++){
		for(int j=0;j<=50;j++){
			ans[i][j] = 'B';
		}		
	}

	for(int i=25;i<=36;i++){
		for(int j=0;j<=50;j++){
			ans[i][j] = 'C';
		}		
	}

	for(int i=37;i<=50;i++){
		for(int j=0;j<=50;j++){
			ans[i][j] = 'D';
		}		
	}

	for(int i=1;i<=4;i++){
		if(qt[alf[i]]) fill(alf[i]);
	}

	cout << 50 << " " << 50 << endl;
	for(int i=1;i<=50;i++){
		for(int j=1;j<=50;j++) cout << ans[i][j];
			cout << endl;
	}

	return 0;
}