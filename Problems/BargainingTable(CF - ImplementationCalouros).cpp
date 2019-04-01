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

int n, m;
char vec[26][26];

int solve(int x, int y, int xx, int yy){

	for(int i=x;i<=xx;i++){
		for(int j=y;j<=yy;j++){
			if(vec[i][j] == '1') return 0;
		}
	}

	return ((xx-x + 1) * 2) + (yy-y+1)*2;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> vec[i][j];
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int _i=i;_i<n;_i++){
				for(int _j=j;_j<m;_j++){
					ans = max(ans, solve(i, j, _i, _j));
				}
			}
		}
	}

	cout << ans << endl;

  return 0;
}