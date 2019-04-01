#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e4 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int t;
vector<string> vec, vec2;

// map<string, int> qt;
map<string, string> ans;
int trie[MAXN][27], endd[MAXN];
int cc[MAXN][27];
int nxt = 1;

void add(string s){
	int node = 0;
	for(int i=0;i<s.size();i++){
		if(trie[node][s[i] - 'a'] == 0){
			node = trie[node][s[i] - 'a'] = nxt++;
      cc[node][s[i] -'a']++;
      // endd[nxt-1]++;
		} else node = trie[node][s[i] - 'a'], cc[node][s[i] - 'a']++;
	}

	endd[nxt - 1]++;
}

int Find(string s){
	int idx = 0;
  string ans = s;
  cout << s << " ";
  for(int i=0;i<s.size();i++){
    if(trie[idx][s[i]-'a'] == 0){
      return 0;
    } else {
      idx = trie[idx][s[i] - 'a'];
      if(cc[idx][s[i]-'a'] == 1){
        cout << s.substr(0, i+1) << endl;
        return 0;
      }
    }
  }
  cout << s << endl;
}

int ult = 1;
bool can(){
  vec2.clear();
  if(ult == vec.size()) return false;
  for(int i=ult;i<=vec.size();i++){
    if(vec[i].size() == 0){
      ult = i+1;
      return true;
    }
    vec2.push_back(vec[i]);
  }
}

void solve(){
  vector<string> vec3 = vec2;

  sort(vec2.begin(), vec2.end());
  
  // for(auto i : vec2) cout << i << endl;

  if(sz(vec2) == 1){
    cout << vec2[0][0] << endl;
    return ;
  }
  
  for(int i=0;i<sz(vec2)-1;i++){
  int pos = 0;
  // cout << vec2[i] << " ";
    if(vec2[i][0] == vec2[i+1][0]){
      for(int j=0;j<vec2[i].size();j++){
        if(j < vec[i+1].size()){
          if(vec2[i][j] != vec2[i+1][j]){
             pos = j;
             break;}
        } else{
          pos = j;
          break;
        }
      }
    } else {
      if(i){
        for(int j=0;j<vec2[i].size();j++){
          if(j < vec2[i-1].size()){
            if(vec2[i][j] != vec2[i-1][j]){
               pos = j;
               break;
               }
          } else{
             pos = j;
             break;
             }
        }
      } else {
        ans[vec2[i]] = vec2[i][0];
        cout << vec2[i][0] << endl;
        continue;
      }
    }
    // cout << vec2[i] << " - " << pos << endl;
    ans[vec2[i]] = vec2[i].substr(0, pos+1);
  }

  string atual = vec2[sz(vec2)-1];
  string anterior = vec2[sz(vec2)-2];
  if(atual[0] == anterior[0]){
    int pos = 0;
    for(int i=0;i<sz(atual);i++){
      if(i < sz(anterior)){
        if(atual[i] != anterior[i]){
          pos = i;
          break;
        }
      } else {
        pos = i;
        break;
      }
    }
    ans[atual] = atual.substr(0, pos+1);
  } else {
    ans[atual] = atual[0];
    // cout << atual << " " << atual[0] << endl;
  }
  for(auto i : vec3) cout << i << " " << ans[i] << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    int t;
    cin >> t;
    bool at = false;
    getchar();
      string s;
      int c = 0;

      while(getline(cin, s)){
        vec.push_back(s);
      }  

      while(can()){

        solve();
        ans.clear();
        cout << endl;
      }

  return 0;
}