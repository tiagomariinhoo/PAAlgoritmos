#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e6 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int

int trie[MAXN][27];
int qt[MAXN][27];
int endd[MAXN];
int nxt = 1;
int ans = 0;
int n, q;

void add(string s){
	int node = 0;
	for(int i=0;i<s.size();i++){
		if(!trie[node][s[i] - 'a']){
			node = trie[node][s[i] -'a'] = nxt++;
			qt[node][s[i] - 'a']++;
		} else {
			node = trie[node][s[i] - 'a'];
			qt[node][s[i] - 'a']++;
		}
	}
	endd[nxt - 1] = 1;
}

int findd(string s){
	int node = 0;
	for(int i=0;i<s.size();i++){
		if(!trie[node][s[i] - 'a']){
			cout << 0 << endl;
			return 0;
		}
		else {
			node = trie[node][s[i] - 'a'];
		}
	}
	cout << qt[node][s[s.size() - 1] - 'a'] << endl;
	// return qt[node][s[s.size() - 1] - 'a'];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for(int i=0;i<n;i++){
  	string a;
  	cin >> a;
  	add(a);
  }

  for(int i=0;i<q;i++){
  	string a;
  	cin >> a;
  	findd(a);
  }

  return 0;
}