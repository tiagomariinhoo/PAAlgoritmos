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
#define MAXL 20

/*

Sobre a L

Basicamente
Se os caminhos tem nós em comum
Vai ficar algo do tipo
A        B
  \___/
  /     \
C        D

Nesse caso, Y vai ser igual a distancia
 de A até C + a distancia de B até D

Ou

A        B
  \___/
  /     \
D        C

Nesse caso, Y vai ser igual a distancia 
de A até D + a distancia de B até C

Então o que sobra é o caminho em comum, 
mas ele tá sendo contado 2 vezes
Por isso divido por 2
E adiciono 1 no fim pois queremos o 
numero de vertices em comum, ao invés do 
numero de arestas
*/

int n, q;
vi vec[MAXN];
int ancestral[MAXN][MAXL];
int nivel[MAXN], pai[MAXN], vis[MAXN];

void dfs(int x){
    vis[x] = 1;
    for(auto i : vec[x]){
        if(vis[i]) continue;
        pai[i] = x;
        nivel[i] = nivel[x] + 1;
        dfs(i);
    }
}

void build(){
    memset(ancestral, -1, sizeof ancestral);
    dfs(1);
    for(int i=1;i<=n;i++) ancestral[i][0] = pai[i];

    for(int j=1;j<MAXL;j++){
        for(int i=1;i<=n;i++){
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
        }
    }
}

int LCA(int u, int v){
    if(nivel[u] < nivel[v]) swap(u, v);
    for(int i=MAXL-1;i>=0;i--){
        if(nivel[u] - (1 << i) >= nivel[v]){
            u = ancestral[u][i];
        }
    }

    if(u == v) return u;

    for(int i=MAXL-1;i>=0;i--){
        if(ancestral[u][i] != -1 and ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    }
    return pai[u];
}

int dis(int a, int b){
    return nivel[a] + nivel[b] - 2*(nivel[LCA(a, b)]);
}

int main(){

    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        vec[a].pb(b);
        vec[b].pb(a);
    }

    build();

    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int aa = dis(a,b) + dis(c, d);
        int bb = min(dis(a,c) + dis(b,d), dis(a, d) + dis(b, c));
        if(aa < bb) cout << 0 << endl;
        else cout << ((aa-bb)/2) + 1 << endl;
    }

    return 0;
}