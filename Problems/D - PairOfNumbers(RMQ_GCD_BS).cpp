#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) (3*(1e5) + 1)
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())

int n;
int vec[MAXN];
int maxi = 0;
vector<int> ans;
int spt[MAXN][MAXL];

void build(){
  for(int j=0;(1<<j)<=n;j++){
		for(int i=0;(i + (1 << j) - 1) < n; i++){
			if(j){
				int pos1 = spt[i][j-1];
				int pos2 = spt[i + (1 << (j-1))][j-1];
				spt[i][j] = vec[pos1] < vec[pos2] ? pos1 : pos2;
			} else {
				spt[i][j] = i;
			}
		}
	}
}

int rmq(int i, int j){
	int len = j - i + 1;
	int k = (int) floor(log((double) len) / log(2.0));
	if(vec[spt[i][k]] <= vec[spt[j-(1<<k)+1][k]]){
		return vec[spt[i][k]];
	} else {
		return vec[spt[j - (1 << k) + 1][k]];
	}
}

bool solve(int atual){
  vector<int> aux;
  // cout << "ATual : " << atual << endl;
  for(int i=0;i<n-atual;i++){
    int divi = rmq(i, i+atual);
    bool at = false;
    // cout << divi << endl;
    for(int j=i;j<=i+atual;j++){
      if(vec[j]%divi!=0){
        at = true;
        break;
      }
    }
    // cout << i << " - " << at << endl;
    if(!at){
      aux.push_back(i+1);
      if(atual != 0)
      i += atual - 1;
    } 
  }
  if(atual >= maxi and aux.size()){
    maxi = atual;
    ans = aux;
    return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++) cin >> vec[i];
  build();

  int com = 0, fim = n-1;
  int it = 0;
  while(com <= fim){
  int mid = (com + fim + 1) >> 1;
  it++;
  if(it >= 20) break; 
    if(solve(mid)){
      com = mid;
    } else fim = mid - 1;
  }

  cout << ans.size() << " " << maxi << endl;
  for(auto i : ans) cout << i << " ";
  cout << endl;

  return 0;
}