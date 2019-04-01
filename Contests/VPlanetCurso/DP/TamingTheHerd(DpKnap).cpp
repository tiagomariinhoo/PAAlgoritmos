#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e4 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<int> vec;

int pd[101][101][101];

int solve(int pos, int tam, int atual){
  if(pos == sz(vec)){
    if(!tam) return 0;
    return -INT_MAX;
  }
  
  int &ans = pd[pos][tam][atual];
  if(ans != -1) return ans;

  int a = solve(pos+1, tam, atual + 1) + (vec[pos] == atual ? 1 : 0);

  if(tam){
    int b = solve(pos+1, tam - 1, 1) + (vec[pos] == 0 ? 1 : 0);
    return ans = max(a, b);
  }

  return ans = a;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ifstream cin("taming.in");
  ofstream cout("taming.out");

  cin >> n;
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vec.push_back(a);
  }

  for(int i=1;i<=n;i++){
    memset(pd, -1, sizeof pd);
    int ans = solve(1, i-1, 1) + (vec[0] == 0 ? 1 : 0);
    cout << n - ans << endl;
  }
  return 0;
}