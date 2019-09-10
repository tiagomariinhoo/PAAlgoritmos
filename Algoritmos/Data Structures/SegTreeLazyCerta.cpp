#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define MOD2 (lli) 998244353  
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n,q;
int vec[MAXN];
int lazy[4*MAXN];
int tree[4*MAXN];

void build(int node = 1, int start = 1, int end = n){
  if(start == end) tree[node] = vec[start];
  else {
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
  }
}

/*
Se for max e min
tree[node] += lazy[node];
Se for Soma do range
tree[node] += (end - start + 1) * val;
*/

void prop(int node, int start, int end){
  tree[node] += (end - start + 1)*lazy[node];
  if(start != end){
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int l, int r, int val, int node = 1, int start = 1, int end = n){
  prop(node, start, end);
  if(start > r or end < l) return ;
  if(start >= l and end <= r){
    lazy[node] += val;
    prop(node, start, end);
    return ;
  }
  int mid = (start + end) >> 1;
  update(l, r, val, 2*node, start, mid);
  update(l, r, val, 2*node+1, mid+1, end);
  tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int l, int r, int node = 1, int start = 1, int end = n){
  prop(node, start, end);
  if(start > end or start > r or end < l) return 0;

  if(start >= l and end <= r) return tree[node];

  int mid = (start + end) >> 1;
  int p1 = query(l, r, 2*node, start, mid);
  int p2 = query(l, r, 2*node+1, mid+1, end);

  return p1+p2;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for(int i=1;i<=n;i++) cin >> vec[i];

  build();
  cout << query(1, 4) << endl;
  update(1, 4, 1);
  cout << query(1, 4) << endl;

  return 0;
}