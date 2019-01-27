#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define F first
#define S second

int tree[4*MAXN], vec[MAXN], tree2[4*MAXN], lazy[4*MAXN];
int n, q;
int ans = 0;
vector<int> con;
vector<pair< pair<int, int>, int> > segs;

/*
	Sweep Line, ordena os segmentos e usar seg tree com lazy
	Pra usar max e min na lazy
	ao invés de usar (end - start + 1) * val
	usa só o val
*/

void build(int node = 1, int start = 1, int end = n){
	if(start == end){
		tree[node] = vec[start];
		tree2[node] = vec[start];
	} else {
		int mid = (start + end) >> 1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = max(tree[2*node], tree[2*node+1]);
		tree2[node] = min(tree2[2*node], tree2[2*node+1]);
	}
}

void lazyUpdate(int l, int r, int val, int node = 1, int start = 1, int end = n){
	if(lazy[node] != 0){
		// tree[node] += (end - start + 1) * lazy[node];
		tree[node] += lazy[node];
		tree2[node] += lazy[node];
		// tree2[node] += (end - start + 1) * lazy[node];
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start > end or start > r or end < l) return ;
	// if(start == end){
		// tree[node] += val;
		// tree2[node] += val;
		// return ;
	// }

	if(start >= l and end <= r){
		// tree[node] += (end - start + 1) * val;
		// tree2[node] += (end - start + 1) * val;
		tree[node] += val;
		tree2[node] += val;
		if(start != end){
			lazy[2*node] += val;
			lazy[2*node+1] += val;
		}
			return ;
	}

	int mid = (start + end) >> 1;
	lazyUpdate(l, r, val, 2*node, start, mid);
	lazyUpdate(l, r, val, 2*node+1, mid+1, end);
	tree[node] = max(tree[2*node], tree[2*node+1]);
	tree2[node] = min(tree2[2*node], tree2[2*node+1]);
}

void updateRange(int l, int r, int val, int node = 1, int start = 1, int end = n){
	if(start > end or start > r or end < l) return ;
	if(start == end){
		tree[node] += val;
		tree2[node] += val;
		return ;
	}
	int mid = (start + end) >> 1;
	updateRange(l, r, val, 2*node, start, mid);
	updateRange(l, r, val, 2*node+1, mid+1, end);
	tree[node] = max(tree[2*node], tree[2*node+1]);
	tree2[node] = min(tree2[2*node], tree2[2*node+1]);
}

pair<int, int> lazyQuery(int l, int r, int node = 1, int start = 1, int end = n){
	if(start > end or start > r or end < l) return {-INT_MAX, INT_MAX};
	if(lazy[node] != 0){
		// tree[node] += (end - start + 1) * lazy[node];
		// tree2[node] += (end - start + 1) * lazy[node];
		tree[node] += lazy[node];
		tree2[node] += lazy[node];
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start >= l and end <= r) return {tree[node], tree2[node]};

	int mid = (start + end) >> 1;
	pair<int, int> p1, p2;
	p1 = lazyQuery(l, r, 2*node, start, mid);
	p2 = lazyQuery(l, r, 2*node+1, mid+1, end);
	return {max(p1.first, p2.first), min(p1.second, p2.second)};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;

  for(int i=1;i<=n;i++){
  	cin >> vec[i];
  }

  memset(tree, -INT_MAX, sizeof tree);
  memset(tree2, INT_MAX, sizeof tree2);
  build();

  for(int i=0;i<q;i++){
  	int a, b;
  	cin >> a >> b;
  	segs.push_back({{a, b}, i+1});
  }

  sort(segs.begin(), segs.end());

  lazyUpdate(1, n, 1);
  pair<int, int> a = lazyQuery(1, n);
  // cout << a.F << " " << a.S << endl;
  ans = a.F - a.S;

  for(int i=0;i<segs.size();i++){
  	vector<int> aux;

  	for(int j=i;j<segs.size();j++){
  		lazyUpdate(segs[j].F.F, segs[j].F.S, -1);
	  	pair<int, int> atual = lazyQuery(1, n);
	  	aux.push_back(segs[j].S);
	  	// cout << atual.F << " - " << atual.S << endl;
	  	if(atual.F - atual.S >= ans){
	  		ans = atual.F - atual.S;
	  		con = aux;
	  	}
  	}

  	for(int j=i;j<segs.size();j++){
  		lazyUpdate(segs[j].F.F, segs[j].F.S, 1);
  	}
  }

  cout << ans << endl;
  cout << con.size() << endl;
  for(auto i : con) cout << i << " ";
  cout << endl;

  return 0;
}