#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(1)
#define MAXN 50500
#define MAX 160005
#define MAXL 20
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
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
typedef pair<string, pair<int, char> > ps;
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

int n,m;
char mat[51][51], aux[51][51];
map<ii, int> mov;

void bfs(int x, int y, int move, int at){
	// cout << x << " - " << y << " - " << move << " - " << at << endl;
	if(move == -1){
		for(int i=0;i<4;i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			if(xx >= 0 and xx < n and yy >= 0 and yy < m){
				if(mat[xx][yy] == 'B'){
					mat[xx][yy] = '*';
				}
					if(mat[xx][yy] != 'W')
					bfs(xx, yy, mov[{dx[i], dy[i]}], 0);
			}
		}
	} else {
		for(int i=0;i<4;i++){
			int xx = x + dx[i];
			int yy = y + dy[i];
			// cout << xx << " - " << yy << endl;
			if(xx >= 0 and xx < n and yy >= 0 and yy < m){
				if(mat[xx][yy] == 'B' or mat[xx][yy] == '*'){
					if(mov[{dx[i], dy[i]}] == move) mat[xx][yy] = '*', bfs(xx, yy, move, 0);
					else{
						int xxx = xx, yyy = yy;
						while(xxx >= 0 and xxx < n and yyy >= 0 and yyy < m){
							mat[xxx][yyy] = '*';
							xxx += dx[i], yyy += dy[i];
							if(xxx >=0 and xxx < n and yyy >= 0 and yyy < m){
								if(mat[xxx][yyy] == 'W') break;
							}
						}
					}
				}
			}
		}
	}
}

void copy(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) mat[i][j] = aux[i][j];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	int x = -1, y = -1;
	vector<ii> c;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> mat[i][j];
			if(mat[i][j] == 'B') c.pb({i,j});
		}
	}

	mov[{0, 1}] = 1, mov[{0, -1}] = 2, mov[{1, 0}] = 3, mov[{-1, 0}] = 4;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) aux[i][j] = mat[i][j];
	}

	for(int i=0;i<sz(c);i++){
		int x = c[i].F, y = c[i].S;
		copy();
		mat[x][y] = '*';
		bfs(x, y, -1, 0);
		bool at = false;
		// cout << x << " - " << y << endl;

		// for(int j=0;j<n;j++){
		// 	for(int k=0;k<m;k++) cout << mat[j][k] << " ";
		// 	cout << endl;
		// }

		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++) if(mat[j][k] == 'B'){
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}