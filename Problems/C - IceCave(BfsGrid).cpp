#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(1e6 + 1)
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
char vec[501][501];
int x, y, xx, yy;
bool at = false;

void solve(int x, int y){
  for(int i=0;i<4;i++){
    int _x = x + dx[i], _y = y + dy[i];
    if(_x >= 0 and _x < n and _y >= 0 and _y < m){
        if(_x == xx and _y == yy){
          vec[x][y]++;
          if(vec[_x][_y]) at = true;
          else {
            for(int j=0;j<4;j++){
              int _x2 = _x + dx[j], _y2 = _y + dy[j];
              if(_x2 < n and _x2 >= 0 and _y2 >= 0 and _y2 < m){
                if(vec[_x2][_y2] == 0) at = true;
              }
            }
          }
          vec[x][y]--;
        } else {
          if(vec[_x][_y] == 0){
            vec[x][y]++;
            solve(_x, _y);
            // vec[x][y]--;
          }
        }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char a;
      cin >> a;
      if(a == '.') vec[i][j] = 0;
      else vec[i][j] = 1;
    }
  }

  cin >> x >> y;
  cin >> xx >> yy;
  x--, y--, xx--, yy--;
  solve(x, y);

  if(at) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}