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


struct MyQueue{
  stack<pair<lli,lli>> s1, s2;

  int size(){
    return sz(s1) + sz(s2);
  }

  bool isEmpty(){
    return size() == 0;
  }

  lli getMax(){
    if(isEmpty()){
      return 0;
    }

    if(!s1.empty() and !s2.empty()){
      return max(s1.top().S, s2.top().S);
    }

    if(!s1.empty()){
      return s1.top().S;
    }

    return s2.top().S;
  }

  void push(lli val){
    if(s2.empty()) s2.push({val, val});
    else s2.push({val, max(val, s2.top().S)});
  }

  void pop(){
    if(s1.empty()){
      while(!s2.empty()){
        if(s1.empty()){
          s1.push({s2.top().F, s2.top().F});
        } else {
          s1.push({s2.top().F, max(s2.top().F, s1.top().S)});
        }
        s2.pop();
      }
    }

    assert(!s1.empty());
    s1.pop();
  }
};

int n, k, x;
lli vec[5001];
lli pd[5050][5050];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k >> x;
  vector<lli> vec(n+1);
  for(int i=1;i<=n;i++) cin >> vec[i];

  vector<vector<lli>> pd(x+5, vector<lli>(n+5, -LLONG_MAX));

  for(int i=1;i<=k;i++) pd[1][i] = vec[i];
  for(int j=2;j<=x;j++){
    MyQueue q;
    for(int i=j;i<=n;i++){
      if(q.size() < k) q.push(pd[j-1][i-1]);
      else q.pop(), q.push(pd[j-1][i-1]);

      // cout << i << " : : " << q.size() << endl;
      // cout << "Maxi : " << q.getMax() << endl;
      if(q.getMax() > -LLONG_MAX)
      pd[j][i] = max(pd[j][i], q.getMax() + vec[i]);
      // cout << j << " - " << i << " : " << pd[j][i] << endl;
      // cout << q.getMax() << " -- " << vec[i] << endl;


    }
  }


  lli ans = -1;

  if(k == 1 and x < n){
    cout << -1 << endl;
    return 0;
  }

  for(int i=n;i>n-k;i--) ans = max(ans, pd[x][i]);

  if(ans > 0)
    cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}  