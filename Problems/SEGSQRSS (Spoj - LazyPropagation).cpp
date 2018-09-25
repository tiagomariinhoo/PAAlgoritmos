#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL LLONG_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF 99999999
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

#define MAXN 100001
int n, q;
int tree[4*MAXN], lazy[4*MAXN], lazy2[4*MAXN];
int tree2[4*MAXN];
int a[MAXN];

/*
Update: Somar valores no range e setar valores do range
Query: Retornar a soma dos quadrados do range ai² + ai+1² + ai+2²...

Duas lazys e duas arvores, uma arvore com os valores normal e uma arvore
com os valores ao quadrado
Uma lazy pro update tipo 1 e 1 lazy pro update tipo 2

Para o tipo de setar, basta fazer: tree[node] = (end - start + 1) * val * val;
para a soma, basta: soma do range dos quadrados + (r - l + 1) * (val*val)
+ 2*val*(soma do range normal)

*/

void build(int node = 1, int start = 1, int end = n){
  if(start == end) tree[node] = a[start]*a[start], tree2[node] = a[start];
  else{
    int mid =(start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
    tree2[node] = tree2[2*node] + tree2[2*node+1];
  }
}

void appLazy(int node, int start, int end){

  if(lazy2[node]){
    tree[node] = (end - start + 1)*lazy2[node]*lazy2[node];
    tree2[node] = (end - start + 1) * lazy2[node];
    if(start != end){
      lazy2[2*node] = lazy2[node], lazy2[2*node+1] = lazy2[node];
    }
    lazy2[node] = 0;
  }

  if(lazy[node] != 0){
    tree[node] = tree[node] + (end - start + 1)*(lazy[node]*lazy[node]) + 2*lazy[node]*tree2[node];
    tree2[node] += (end - start + 1)*lazy[node];

    if(start != end){
      lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void update2(int l, int r, int val, int node = 1, int start = 1, int end = n){
  if(start > end or start > r or end < l) return;
  if(start >= l and end <= r){
    tree[node] = (end - start + 1) * val * val;
    tree2[node] = (end - start + 1) * val;
    if(start != end){
      lazy2[2*node] = val;
      lazy2[2*node+1] = val;
    }
    lazy[node] = 0, lazy2[node] = 0;
    return ;
  }

  int mid = (start + end) >> 1;
  update2(l, r, val, 2*node, start, mid);
  update2(l, r, val, 2*node+1, mid+1, end);
  tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int l, int r, int val, int node = 1, int start = 1, int end = n){
  if(start > end or start > r or end < l) return ;

  appLazy(node, start, end);
  if(start >= l and end <= r){
    // tree2[node] += (end - start + 1)*lazy[node];
    tree[node] = tree[node] + (end - start + 1)*(val*val) + 2*val*tree2[node];
    tree2[node] += (end - start + 1)*val;
    if(start != end){
      lazy[2*node] += val;
      lazy[2*node+1] += val;
      return ;
    }
  }
  int mid = (start + end) >> 1;
  update(l, r, val, 2*node, start, mid);
  update(l, r, val, 2*node+1, mid+1, end);
  tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int l, int r, int node = 1, int start = 1, int end = n){
  if(start > r or end < l) return 0;
  appLazy(node, start, end);

  if(start >= l and end <= r){
    return tree[node];
  }

  int mid = (start + end) >> 1;
  int p1 = query(l, r, 2*node, start, mid);
  int p2 = query(l, r, 2*node+1, mid+1, end);
  return p1+p2;
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >>t;
  int tt = 1;
  while(t--){
    cin >> n >> q;
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    memset(lazy2, 0, sizeof lazy2);
    for(int i=1;i<=n;i++) cin >> a[i];
    build();
    cout << "Case " << tt++ << ":" <<  endl;
    for(int i=0;i<q;i++){
      int aa;
      cin >> aa;

      // for(int j=1;j<=n;j++) cout << query(j,j) << " ";
      //   cout << endl;

      if(aa == 0){
        int l, r, x;
        cin >> l >> r >> x;
        update2(l, r, x);
      } else if(aa == 1){
        int l, r, x;
        cin >> l >> r >> x;
        update(l, r, x);
      } else if(aa == 2){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
      }
    }
  }

   return 0; 
} 