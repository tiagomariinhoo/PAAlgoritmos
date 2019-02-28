#include <bits/stdc++.h>
using namespace std;

#define MAXN 300010
#define MAXL 20
#define F first
#define S second
#define lli long long int

int trie[MAXN][27], end[MAXN];
int nxt = 1;

void add(string s){
	int node = 0;
	for(int i=0;i<s.size();i++){
		if(trie[node][s[i] - 'a'] == 0){
			node = trie[node][s[i] - 'a'] = nxt++;
		} else node = trie[node][s[i] - 'a'];
	}
	end[nxt - 1] = 1;
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
	return end[idx];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  

  return 0;
}