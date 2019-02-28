#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e5 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int

int n;
vector<lli> vec;
map<lli, lli> qt;
lli pd[MAXN];

lli solve(int obj){
	if(obj >= vec.size()) return 0;

	if(pd[obj] != -1) return pd[obj];

	lli a = solve(obj+1);
	lli b = 0, c = 0;

	if(obj == vec.size() - 1){
		b = (solve(obj+1) + qt[vec[obj]]*vec[obj]);
	} else {
		if(vec[obj + 1] == vec[obj] + 1) b = (solve(obj+2) + qt[vec[obj]]*vec[obj]);
		else b = (solve(obj+1) + qt[vec[obj]]*vec[obj]);
	}

	return pd[obj] = max(a, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  set<int> aux;
  for(int i=0;i<n;i++){
  	int a;
  	cin >> a;
  	aux.insert(a);
  	qt[a]++;
  }
  
  for(auto i : aux) vec.push_back(i);
  memset(pd, -1, sizeof pd);

  cout << solve(0) << endl;

  return 0;
}