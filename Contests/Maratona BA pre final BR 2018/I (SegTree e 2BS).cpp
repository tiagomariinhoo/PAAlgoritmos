#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAX INT_MAX
#define MAXLL INT_MAX
#define MAXU ULLONG_MAX
#define MIN -2000000
#define endl "\n"
#define INF INT_MAX
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
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100010
#define MAXL 20
#define MOD2 998244353

int n, q;
int vec[MAXN];
int dif[MAXN];
int tree[4*MAXN];

void build(int node = 1, int start = 1, int end = n-1){
  if(start == end) tree[node] = dif[start];
  else{
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

int query(int l, int r, int node = 1, int start = 1, int end = n-1){
  if(start > r or end < l) return 0;
  if(start >= l and end <= r) return tree[node];
  int mid = (start + end) >> 1;
  int p1 = query(l, r, 2*node, start, mid);
  int p2 = query(l, r, 2*node+1, mid+1, end);
  return max(p1, p2);
}

void update(int idx, int val, int node = 1, int start = 1, int end = n - 1){
  if(start == end){
    tree[node] = val;
  } else {
    int mid = (start + end) >> 1;
    if(start <= idx and idx <= mid) update(idx, val, 2*node, start, mid);
    else update(idx, val, 2*node+1, mid+1, end);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

void solve(int pos, int h){

  if(pos == n) pos--;
  else {
    if(pos > 1)
    if(query(pos, pos) > h) pos--;
  }
  // for(int i=1;i<=n-1;i++) cout << query(i,i) << " ";
    // cout << endl;

  int com = 1, fim = pos;
  int ans1 = pos, ans2 = pos;
  while(com < fim){
    int mid = (com + fim) >> 1;
    // cout << "mid - " << mid << endl;
    // cout << query(mid, pos) << endl;
    if(query(mid, pos) <= h)fim = mid, ans1 = mid;
    else com = mid + 1;
  }

  com = pos, fim = n-1;
  while(com < fim){
    int mid = (com + fim + 1) >> 1;
    // cout << "Mid " << mid << endl;
    // cout << query(pos, mid) << endl;
    if(query(pos, mid) <= h) com = mid, ans2 = mid;
    else fim = mid - 1;
  }

  // cout << "Anss:" << endl;
  // cout << ans1 << " " << ans2 << endl;
  if(ans2 - ans1 == 1){
    if(abs(vec[ans2] - vec[ans2 + 1] <= h)) cout << 3 << endl;
    else cout << 2 << endl;
  } else if(ans2 - ans1 == 0){
    if(abs(vec[ans1] - vec[ans1+1]) <= h) cout << 2 << endl;
    else cout << 1 << endl;
  } else {
    if(abs(vec[ans2] - vec[ans2 + 1]) <= h) cout << ans2 - ans1 + 2 << endl;
    else cout << ans2 - ans1 + 1 << endl;
  }

}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for(int i=1;i<=n;i++) cin >> vec[i];

  for(int i=1;i<=n-1;i++) dif[i] = abs(vec[i] - vec[i+1]);

  build();

  if(n == 1){
    for(int i=0;i<q;i++){
      int a, b, c;
      cin >> a >> b >> c;
      if(c == 2){
        cout << 1 << endl;
      }
    }
    return 0;
  }

  for(int i=0;i<q;i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1){ 
      // if(c > vec[b]) aux *= -1;
      int aux;
      if(b == 1){
        aux = abs(c - vec[2]);
        // aux *= -1;
        update(1, aux);
      } else if(b == n){
        aux = abs(c - vec[n-1]);
        // aux *= -1;

        update(n-1, aux);
      } else {
        int dif = abs(c - vec[b+1]);
        int dif2 = abs(c - vec[b-1]);
        // dif *= -1, dif2 *= -1;
        // cout << dif << " - " << dif2 << endl;
        update(b, dif);
        update(b-1, dif2);
      }
      vec[b] = c;
    } else {
      solve(b, c);
    }
  }

  return 0;
}