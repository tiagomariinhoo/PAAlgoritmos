#include <bits/stdc++.h>
using namespace std;

#define MAXN 300010
#define MAXL 20
#define F first
#define S second
#define lli long long int
#define sz(a) int(a.size())

int trie[MAXN][27], endd[MAXN];
int c[MAXN][27];
int nxt = 1;

void add(string s){
	int node = 0;
	for(int i=0;i<s.size();i++){
		if(trie[node][s[i] - 'a'] == 0){
			node = trie[node][s[i] - 'a'] = nxt++;
      c[node][s[i] -'a']++;
      endd[nxt-1]++;
		} else node = trie[node][s[i] - 'a'], c[node][s[i] - 'a']++;
	}

	endd[nxt - 1]++;
}

int Find(string s){
	int idx = 0;
	for(int i=0;i<s.size();i++){
		if(trie[idx][s[i] - 'a'] == 0){
			return 0;
		} else {
			idx = trie[idx][s[i] - 'a'];
		}
	}
  if(endd[idx]) return c[idx][s[sz(s)-1]-'a'];
	return endd[idx];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string atual = "abacate";
  string atual2 = "abacaxi";
  add(atual);
  add(atual2);
  string aux = "";
  add("a");
  for(int i=0;i<atual.size();i++){
    aux += atual[i];
    cout << "Aux : " << aux << endl;
    cout << Find(aux) << endl;
  }

  return 0;
}