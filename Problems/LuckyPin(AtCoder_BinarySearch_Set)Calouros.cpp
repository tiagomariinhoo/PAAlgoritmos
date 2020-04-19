#include<bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (lli)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
#define PI 2 * acos(0.0)
typedef pair<int,int> ii;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n;
string s;
map<int, set<int> > pos;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  cin >> s;

  for(int i=0;i<sz(s);i++){
    int a = s[i] - '0';
    pos[a].insert(i);
  }

  int ans = 0;
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=9;k++){
        if(sz(pos[i]) == 0
        or sz(pos[j]) == 0
        or sz(pos[k]) == 0) continue;
        int pos1 = *pos[i].begin();
        int pos2 = *pos[j].upper_bound(pos1);
        if(pos[j].find(pos2) != pos[j].end()){
          int pos3 = *pos[k].upper_bound(pos2);
          if(pos[k].find(pos3) != pos[k].end()){
            if(pos2 > pos1 and pos3 > pos2){
              // cout << i << " - " << j << " - " << k << endl;
              ans++;
            }
          }
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}
