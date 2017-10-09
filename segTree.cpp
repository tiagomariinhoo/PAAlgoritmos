#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1001
#define MIN -2000000
#define INF 9000000000000000000
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second

int tree[MAX];
int A[MAX];
int n;

void build(int node, int start, int end){
	// cout << "Node : " << node << " / Start : " << start << " / End : " << end << endl;

	if(start==end) tree[node] = A[start];
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);

		tree[node] = tree[2*node] + tree[2*node+1];
	}
	// cout << "Tree[node] : " << tree[node] << endl;
	// cout << "------" << endl;
}

void update(int node, int start, int end, int idx, int val){
	if(start == end){
		A[idx] += val;
		tree[node] += val;
	} else {
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid) update(2*node, start, mid, idx, val);
		else update(2*node+1, mid+1, end, idx, val);

		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int start, int end, int l, int r){
	cout << "Node : " << node << endl;
	if(r < start or end < l) return 0;

	if(l <= start and end <= r) return tree[node];

	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l ,r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return (p1+p2);
}

int main(){

	cin >> n;
		for(int i=1;i<=n;i++) cin >> A[i];

			build(1, 1, n); //Node = root
			for(int i=1;i<=n;i++) cout << A[i] << " ";
				cout << endl;
			for(int i=1;i<=2*n+1;i++) cout << "Tree [" << i << "]" << " - " << tree[i] << endl;

				cout << query(1, 1, n, 1, 6) << endl;

				update(1, 1, n, 2, 1); //O val soma com o conteudo do idx
				for(int i=1;i<=n;i++) cout << A[i] << " ";
					cout << endl;
				cout << "New Tree : " << endl;
			for(int i=1;i<=2*n+1;i++) cout << "Tree [" << i << "]" << " - " << tree[i] << endl;




	return 0;
}