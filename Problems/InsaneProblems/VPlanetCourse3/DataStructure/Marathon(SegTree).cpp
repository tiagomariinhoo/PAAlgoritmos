#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int n, q;
int tree[4*MAXN], delta[4*MAXN];
pair<int, int> vec[MAXN];
 
int getDist(int i, int j){
  return abs(vec[i].F - vec[j].F) + abs(vec[i].S - vec[j].S);
}
 
int getTree(int idx){
  if(idx < n){
    return getDist(idx, idx+1);
  }
  return 0;
}
 
int getDelta(int idx){
  if(idx <= n-1 and idx >= 2){
    return getDist(idx-1, idx) + getDist(idx, idx+1) - getDist(idx-1, idx+1);
  }
  return 0;
}
 
void build(int node = 1, int start = 1, int end = n){
  if(start == end){
    tree[node] = getTree(start);
    delta[node] = getDelta(start);
  } else {
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
    delta[node] = max(delta[2*node], delta[2*node+1]);
  }
}
 
int queryTree(int l, int r, int node = 1, int start = 1, int end = n){
  if(start > r or end < l) return 0;
  if(start >= l and end <= r) return tree[node];
 
  int mid = (start + end) >> 1;
  int p1 = queryTree(l, r, 2*node, start, mid);
  int p2 = queryTree(l, r, 2*node+1, mid+1, end);
  return p1+p2;
}
 
int queryDelta(int l, int r, int node = 1, int start = 1, int end = n){
  if(start > r or end < l) return 0;
  if(start >= l and end <= r) return delta[node];
 
  int mid = (start + end) >> 1;
  int p1 = queryDelta(l, r, 2*node, start, mid);
  int p2 = queryDelta(l, r, 2*node+1, mid+1, end);
  return max(p1, p2);
}
 
void update(int idx, int node = 1, int start = 1, int end = n){
  if(start == end){
    tree[node] = getTree(idx);
    delta[node] = getDelta(idx);
  } else {
    int mid = (start + end) >> 1;
    if(start <= idx and idx <= mid) update(idx, 2*node, start, mid);
    else update(idx, 2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
    delta[node] = max(delta[2*node], delta[2*node+1]);
  }
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   
 
  freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
 
  cin >> n >> q;
  for(int i=1;i<=n;i++) cin >> vec[i].F >> vec[i].S;
 
  build();
 
  while(q--){
    char op;
    cin >> op;
    if(op == 'Q'){
      int l, r;
      cin >> l >> r;
 
      if(r - l + 1 <= 1){
        cout << queryTree(l, l) << endl;
        continue;
      }
 
      int sum = queryTree(l, r-1);
      int aux = queryDelta(l+1, r-1);
      if(r - l + 1 <= 2){
        cout << sum << endl;
        continue;
      }
 
      cout << sum - aux << endl;
    } else {
      int idx, x, y;
      cin >> idx >> x >> y;
      vec[idx].F = x, vec[idx].S = y;
      for(int i=idx-1;i<=idx+1;i++) update(i);
    }
  }
 
  return 0;
}