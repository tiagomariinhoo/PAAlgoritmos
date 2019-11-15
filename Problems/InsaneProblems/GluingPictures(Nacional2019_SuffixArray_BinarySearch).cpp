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
#define PI 2 * acos(0.0)
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

set<int> aa;
string txt, pat;
vector<int> SA;
int n, m;

vector<int> sort_cyclic_shifts(string s){
  int n = s.size();
  int alphabet = 256;

  vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
  for(int i=0;i<n;i++) cnt[s[i]]++;
  for(int i=1;i<alphabet;i++) cnt[i] += cnt[i-1];
  for(int i=0;i<n;i++) p[--cnt[s[i]]] = i;
  c[p[0]] = 0;
  int classes = 1;
  for(int i=1;i<n;i++){
    if(s[p[i]] != s[p[i-1]]) classes++;
    c[p[i]] = classes - 1;
  }

  vector<int> pn(n), cn(n);

  for(int h=0;(1<<h) < n; h++){
    for(int i=0;i<n;i++){
      pn[i] = p[i] - (1 << h);
      if(pn[i] < 0) pn[i] += n;
    }
    fill(cnt.begin(), cnt.begin() + classes, 0);
    for(int i=0;i<n;i++) cnt[c[pn[i]]]++;
    for(int i=1;i<classes;i++) cnt[i] += cnt[i-1];
    for(int i=n-1;i>=0;i--) p[--cnt[c[pn[i]]]] = pn[i];
    cn[p[0]] = 0;
    classes  = 1;
    for(int i=1;i<n;i++){
      pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
      pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
      if(cur != prev) ++classes;
      cn[p[i]] = classes - 1;
    }
    c.swap(cn);
  }
  return p;
}

vector<int> suffix_array_construction(string s){
  s += "$";
  vector<int> sorted_shifts = sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}

void solve(){
  set<int> aux;
  for(auto i : txt){
    aux.insert(i);
  }

  for(auto i : pat){
    if(aux.find(i) == aux.end()){
      cout << -1 << endl;
      return ;
    }
  }

  int l = 0, r = sz(txt) - 1;
  int tam = 0, ans = 1;
  for(int i=0;i<sz(pat);i++){
    char atual = pat[i];
    bool at = false;

    int com = l, fim = r;
    int poss = l;
    while(com <= fim){
      int mid = (com+fim) >> 1;
      int pos = SA[mid];
      if(txt[pos+tam] < atual){
        com = mid + 1;
      } else if(txt[pos+tam] > atual){
        fim = mid - 1;
      } else {
        poss = mid;
        fim = mid - 1;
        at = true;
      }
    } 

    if(!at) { //Não achou
      l = 0, tam = 0, r = sz(txt) - 1;
      i--;
      ans++;
    } else { //Achou
      com = poss;
      fim = r;
      int pos2 = l;
      while(com <= fim){
        int mid = (com + fim) >> 1;
        int pos = SA[mid];
        if(txt[pos+tam] < atual){
          com = mid + 1;
        } else if(txt[pos+tam] > atual){
          fim = mid - 1;
        } else {
          pos2 = mid;
          com = mid + 1;
        }
      }
      l = poss, r = pos2;
      tam++;
    }
  }

  cout << min(ans, sz(pat)) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> txt;
  SA = suffix_array_construction(txt);

  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> pat;
    solve();
  }

  return 0;
}