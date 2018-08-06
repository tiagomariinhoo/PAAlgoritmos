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

void build(int node = 1, int start = 1, int end = n){
	if(start == end) tree[node] = A[start];
	else{
		int mid = (start + end) >> 1;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}



int query(int l, int r, int node = 1, int start = 1, int end = n){
	if(r < start or end < l) return -1;
	if(l <= start and end <= r) return tree[node];

	int mid = (start + end) >> 1;
	int p1 = query(l , r, 2*node, start, mid);
	int p2 = query(l , r,2*node+1, mid+1, end);
	//if(p1 == -1) return p2;
	//if(p2 == -1) return p1;
	return max(p1,p2);
}

int main(){
	s(n);
		for(int i=1;i<=n;i++) s(A[i]);

		build();

		//for(int i=1;i<=2*n+1;i++) cout << tree[i] << endl;
			cout << "------" << endl;
		cout << query(2, 4) << endl;

		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){

			}
		}



	return 0;
}