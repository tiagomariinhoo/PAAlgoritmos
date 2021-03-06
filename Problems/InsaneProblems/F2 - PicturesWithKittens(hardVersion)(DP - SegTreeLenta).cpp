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
#define pb push_back
#define mp make_pair
#define M_PI 3.14159265358979323846
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
// typedef pair<int,int> ii;
#define DEBUG if(1)
#define F first
#define S second
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 5010
#define MAXL 20
#define MOD2 998244353

/*
  Problema:
  Dado um array de n elementos, k e x
  Pegar X elementos desse array de forma que não tenha um
  intervalo maior que K entre os elementos pegos.
  5 2 3
  5 1 3 10 1, resposta: 18, pegando 5, 3 e 10

  Para otimizar e usar com 5000 elementos
  É preciso usar pd bottom up, onde
  pd[i][j], i = elemento atual que estamos pegando,
  j = número de elementos repostados
  
  (nesse caso da solução, foi o contrário)
  Podemos pegar o max no intervalo da dp e já substituir


*/

int n, k, x;
vector<lli> vec2;
vector<lli> tree;
void build(int node, int start, int end){
    if(start == end) tree[node] = vec2[start];
    else {
      int mid = (start + end) >> 1;
      build(node << 1, start, mid);
      build(node << 1 | 1 , mid+1, end);
      tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
    }
  }

lli query(int l, int r, int node, int start, int end){
  if(l == start and end == r) return tree[node];
  int mid = (start + end) >> 1;
  if(l > mid){
    return query(l, r, node << 1 | 1, mid + 1, end);
  } else if(r < mid + 1){
    return query(l, r, node << 1, start, mid);
  } else {
    return max(query(l, min(mid, r), node << 1, start, mid), 
      query(max(mid+1, l), r, node << 1 | 1, mid + 1, end));
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}  