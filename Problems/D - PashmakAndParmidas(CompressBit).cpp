#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(1e6 + 1)
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())

int n;
lli ans = 0;
lli tree[MAXN];
vector<int> vec;
map<int, lli> qt, qt2;

void compress(vector<int> &aux){
  vector<int> aux2;
  for(int i=0;i<sz(aux);i++) aux2.push_back(aux[i]);
  sort(aux2.begin(), aux2.end());
  for(int i=0;i<sz(aux);i++){
    aux[i] = lower_bound(aux2.begin(), aux2.end(), aux[i]) - aux2.begin() + 1;
  }
}

void atualiza(int x, int v){
	for(;x<=n;x+=(x&-x)) tree[x] += v;
}

int sum(int x){
	int s = 0;
	for(;x>0;x-=(x&-x)) s += tree[x];
	return s;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vec.push_back(a);
  }

  compress(vec);

  for(int i=sz(vec)-1;i>=1;i--){
    qt[vec[i]]++;
    atualiza(qt[vec[i]], 1);
  }


  for(int i=0;i<vec.size()-1;i++){
    qt2[vec[i]]++;
    
    ans += sum(qt2[vec[i]] - 1);

    atualiza(qt[vec[i+1]], -1);
    qt[vec[i+1]]--;
  }

  cout << ans << endl;

  return 0;
}