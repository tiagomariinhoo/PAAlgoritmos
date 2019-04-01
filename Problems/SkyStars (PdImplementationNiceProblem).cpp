#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n,q,c;
vector<pair<int, pair<int, int> > > vec;
map<pair<int, pair<int, pair<int, pair<int, int> > > >, int> pd;
int vis[102][102][12];
int vis2[102][102];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	cin >> n >> q >> c;
	for(int i=0;i<n;i++){
		int a, b, c;
		cin >> a >> b >> c;
		vec.push_back({c,{a, b}});
		vis2[a][b] = 1;
	}

	for(int i=0;i<vec.size();i++){
		for(int j=0;j<=c;j++){
			int x = vec[i].S.F, y = vec[i].S.S;
			vis[x][y][j] += (vec[i].F+j)%(c+1);
		}
	}

	for(int i=0;i<q;i++){
		int t, x, y, xx, yy;
		cin >> t >> x >> y >> xx >> yy;
		int sum = 0;

		for(int ii=x;ii<=xx;ii++){
			for(int jj=y;jj<=yy;jj++){
				if(vis[ii][jj] or vis2[ii][jj]){
					 sum += (vis[ii][jj][t%(c+1)]);
					}
			}
		}
		cout << sum << endl;
	}

  return 0;
}