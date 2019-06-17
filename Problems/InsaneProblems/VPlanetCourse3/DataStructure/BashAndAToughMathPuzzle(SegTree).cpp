#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(5*1e5 + 10)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
typedef pair<int,int> ii;

int n;
vector<int> vec(MAXN);
int tree[4*MAXN];

bool at = false;
int atual;
int qt = 0;

/*
  Checa se tem dois nodes na segTree que o Gcd não é multiplo
*/

void build(int node = 1, int start = 1, int end = n){
  if(start == end) tree[node] = vec[start];
  else {
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = __gcd(tree[2*node], tree[2*node+1]);
  }
}

int query(int l, int r, int node = 1, int start = 1, int end = n){
  if(at) return 0;
  
  if(start > r or end < l) return 0;
  if(start >= l and end <= r){
    if(tree[node]%atual == 0) return tree[node];
    else {
      if(at) return tree[node];
      if(start != end){
        int mid = (start + end) >> 1;
        int aa = query(l, r, 2*node, start, mid);
        int bb = query(l, r, 2*node+1, mid+1, end);
        if(aa%atual != 0 and bb%atual != 0) at = true;
      }
    }
    return tree[node];
  }

  int mid = (start + end) >> 1;
  int a = query(l, r, 2*node, start, mid);
  int b = query(l, r, 2*node+1, mid+1, end);
  
  if(a%atual != 0 and b%atual != 0) at = true;

  return __gcd(a, b);
}

void update(int idx, int v, int node = 1, int start = 1, int end = n){
  if(start == end) tree[node] = v;
  else {
    int mid = (start + end) >> 1;
    if(start <= idx and idx <= mid){
      update(idx, v, 2*node, start, mid);
    } else {
      update(idx, v, 2*node+1, mid+1, end);
    }
    tree[node] = __gcd(tree[2*node], tree[2*node+1]);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++) cin >> vec[i];

  build();

  int q;
  cin >> q;

  while(q--){
    int op;
    cin >> op;
    if(op == 1){
      int l ,r, x;
      cin >> l >> r >> x;
      qt = 0, at = false, atual = x;
      query(l, r);
      if(at) cout << "NO" << endl;
      else cout << "YES" << endl;
    } else {
      int idx, x;
      cin >> idx >> x;
      update(idx, x);
    }
  }



  return 0;
}