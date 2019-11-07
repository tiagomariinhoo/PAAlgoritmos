#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};
typedef pair<lli, lli> ii;

lli n;
vector<pair<lli, pair<lli, lli > > > vec(2002);
lli k[2002], c[2002];
set<lli> ansEst;
vector<pair<lli,lli> > ansCon;
lli ansSum;
lli pai[2020];
lli papai[2020];
lli dist[2002];
int vis[2002];
lli have[2002];

vector<lli> aux[2002];

lli proc(lli x){
  if(pai[x] == x) return x;
  return pai[x] = proc(pai[x]);
}

void junta(lli a, lli b){
  
  lli at = max({have[a], have[b]});

  a = proc(a);
  b = proc(b);
  at = max({at, have[a], have[b]});
  pai[a] = b;
  have[a] = at, have[b] = at;
}

lli proc2(lli x){
  if(papai[x] == x) return x;
  return papai[x] = proc2(papai[x]);
}

void junta2(lli a, lli b){
  a = proc2(a);
  b = proc2(b);
  papai[a] = b;
  have[a] = have[b];
}

lli dis(pair<lli, lli> a, pair<lli, lli> b){
  return abs(a.F - b.F) + abs(a.S - b.S);
}

void solve(vector<lli> vec2){
  
  lli root = 0, atual = LLONG_MAX;
  for(auto i : vec2){
    if(c[i] < atual) root = i, atual = c[i];
  } 

  ansSum += c[root];
  ansEst.insert(root);
  
  vector<pair<lli, pair<lli, lli> > > auxx;
  for(int i=0;i<sz(vec2);i++){
    for(int j=i+1;j<sz(vec2);j++){
      lli dd = dis(vec[vec2[i]].S, vec[vec2[j]].S) * (k[vec2[i]] + k[vec2[j]]);
      auxx.push_back({dd, {vec2[i], vec2[j]}});
    }
  }

  sort(auxx.begin(), auxx.end());

  for(auto i : auxx){
    if(proc2(i.S.F) != proc2(i.S.S)){
      junta2(i.S.F, i.S.S);
      ansSum += i.F;
      ansCon.push_back({i.S.F, i.S.S});
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=1;i<=n;i++){
    lli a, b;
    cin >> a >> b;
    vec[i].F = i, vec[i].S.F = a, vec[i].S.S = b;
    pai[i] = i;
    papai[i] = i;
    dist[i] = INT_MAX;
  }

  for(int i=1;i<=n;i++) cin >> c[i];
  for(int i=1;i<=n;i++) cin >> k[i];

  vector<pair<lli, ii > > edges;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i == j) continue;
      lli puxarCabo = dis(vec[i].S, vec[j].S) * (k[i] + k[j]);
      edges.push_back({puxarCabo, {i, j}});
    }
  }

  for(int i=1;i<=n;i++) edges.push_back({c[i], {i, 0}});

  sort(edges.begin(), edges.end());

  // for(auto i : edges) cout << i.S.F << " - " << i.S.S << " : " << i.F << endl;

  for(auto i : edges){
    if(have[proc(i.S.S)] and have[proc(i.S.F)]) continue;

    if(i.S.S == 0){
      if(have[proc(i.S.F)] == 0){
        have[proc(i.S.F)] = 1;
        ansEst.insert(i.S.F);
        ansSum += i.F;
        vis[i.S.F] = 1;
      }
    } else {
      if(proc(i.S.F) != proc(i.S.S)){
        ansCon.push_back({i.S.F, i.S.S});
        ansSum += i.F;
        junta(i.S.F, i.S.S);
        // vis[i.S.F] = 1, vis[i.S.S] = 1;
      }
    }
  }

  cout << ansSum << endl;
  cout << sz(ansEst) << endl;
  for(auto i : ansEst) cout << i << " ";
  cout << endl;
  cout << sz(ansCon) << endl;
  for(auto i : ansCon) cout << i.F << " " << i.S << endl;

  return 0;
}