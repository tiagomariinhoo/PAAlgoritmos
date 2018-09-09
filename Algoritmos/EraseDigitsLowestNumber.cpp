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


void insertInNonDecOrder(deque<char> &dq, char ch){ 
    if (dq.empty()) 
        dq.push_back(ch); 
  
    else{ 
        char temp = dq.back(); 
        while( temp > ch && !dq.empty()){ 
            dq.pop_back(); 
            if (!dq.empty()) 
                temp = dq.back(); 
        } 
        dq.push_back(ch);
    } 
    return; 
} 
  
string buildLowestNumber(string str, int n){ 
    int len = str.length(); 
    int k = len - n; 
  
    deque<char> dq; 
    string res = ""; 
  
    int i; 
    for (i=0; i<=len-k; i++) 
  
        insertInNonDecOrder(dq, str[i]); 
  
    while (i < len){ 
        res += dq.front(); 
  
        dq.pop_front(); 
  
        insertInNonDecOrder(dq, str[i]); 
        i++; 
    } 
  
    res += dq.front(); 
    dq.pop_front(); 
    return res; 
} 
  
int main(){ 
	string s;
	int k;
	while(cin >> s >> k){
		cout << buildLowestNumber(s, k) << endl;
	}
    return 0; 
} 