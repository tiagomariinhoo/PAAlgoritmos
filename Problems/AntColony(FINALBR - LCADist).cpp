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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};
#define MAXN 100001
#define MAXL 20

int n;
int ancestral[MAXN][MAXL];
int pai[MAXN];
int nivel[MAXN];
lli dist[MAXN];
vector<ii> vec[MAXN];

void dfs(int x){
    for(auto i : vec[x]){
        int u = i.F, d = i.S;
        nivel[u] = nivel[x] + 1;
        pai[u] = x;
        dist[u] = dist[x] + d;
        dfs(u);
    }
}

void build(){
    memset(ancestral, -1, sizeof ancestral);
    dfs(0);

    for(int i=0;i<n;i++) ancestral[i][0] = pai[i];

    for(int i=0;i<n;i++){
        for(int j=1;j<MAXL;j++){
            ancestral[i][j] = ancestral[ancestral[i][j-1]][j-1];
        }
    }
}

int LCA(int u, int v){
    if(nivel[u] < nivel[v]) swap(u , v);
    for(int i = MAXL-1;i>=0;i--){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int kk = 0;
    while(1){
        cin >> n;
        if(kk) cout << endl;
        if(!n) break;
        memset(pai, 0, sizeof pai);
        memset(nivel, 0, sizeof nivel);
        memset(dist, 0, sizeof dist);
        for(int i=0;i<MAXN;i++) vec[i].clear();
        for(int i=1;i<=n-1;i++){
            int a, b;
            cin >> a >> b;
            vec[a].pb({i, b});
        }

        build();

        // for(int i=0;i<n;i++) cout << i << " - " << dist[i] << endl;

        int q;
        cin >> q;
        for(int i=0;i<q;i++){
            int a, b;
            cin >> a >> b;
            if(i) cout << " ";
            cout << dist[a] + dist[b] - 2*dist[LCA(a, b)];
        } 
        kk++;
    }




    return 0;
}
