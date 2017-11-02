#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF 90000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second

int tree[MAX];
int A[MAX];
int n;

void build(int node=1, int start=1, int end=n){
	if(start == end) tree[node] = A[start];
	else {
		int mid = (start + end) >> 1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

void update(int idx, int val, int node=1, int start=1, int end=n){
	if(start == end){
		A[idx] += val;
		tree[node] += val;
	} else {
		int mid = (start + end) >> 1;
		if(start <= idx and idx <= mid) update(idx, val, 2*node, start, mid);
		else update(idx, val, 2*node+1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int l, int r, int node=1, int start=1, int end = n){
	if(r < start or end < l) return 0;
	if(l <= start and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	int p1 = query(l, r, 2*node, start, mid);
	int p2 = query(l, r, 2*node+1, mid+1, end);
	return (p1+p2);
}
// LAZY PROPAGATION
/*void updateRange(int node, int start, int end, int l, int r, int val){
	if(lazy[node] != 0){
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start > end or star > r or end < l) return;

	if(start >= l and end <= r){
		tree[node] += (end - start + 1) * val;
		if(start != end){
			lazy[node*2] += val;
			lazy[node*2+1] += val;
		}
		return ;
	}
	int mid = (start + end) / 2;
	updateRange(node*2, start, mid, l, r, val);
	updateRange(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int queryRange(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l) return 0;
	if(lazy[node] != 0){
		tree[node] += (end - start + 1) * lazy[node];
		if(start != end){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(start >= l and end <= r) return tree[node];
	int mid = (start + end) / 2;
	int p1 = queryRange(node*2, start, mid, l, r);
	int p2 = queryRange(node*2 + 1, mid + 1, end, l, r);
	return (p1 + p2);
}*/

int main(){
	cin >> n;
		rep(i,1,n+1) s(A[i]);
	build();
	cout << query(1,n) << endl;
	update(2, 1);
	cout << query(1,n) << endl;
}