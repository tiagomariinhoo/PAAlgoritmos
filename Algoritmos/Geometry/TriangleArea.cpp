#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)(2*1e5 + 1)
#define MAXL 20
#define F first
#define endl "\n"
#define S second
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<pair<lli, lli> > vec;
map<pair<lli, lli>, int> idx;

long double area = DBL_MAX;

//Triangle area with 3 points
long double calc(long double x, long double y, long double xx, long double yy, long double xxx, long double yyy){
  return abs((x*(yy-yyy) + xx*(yyy-y) + xxx*(y-yy))/2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    idx[{a,b}] = i+1;
    vec.push_back({a,b});
  }

  sort(vec.begin(), vec.end());
  // for(auto i : vec) cout << i.F << " " << i.S << endl;
  int pos = 0;
  for(int i=2;i<sz(vec);i++){
    long double atual = calc(vec[0].F, vec[0].S, vec[1].F, vec[1].S, vec[i].F, vec[i].S);
    // cout << vec[i].F << " - " << vec[i].S << " : " << atual << endl;
    if(atual < area and atual) pos = i, area = atual;
  }


  cout << idx[{vec[0].F, vec[0].S}] << " ";
  cout << idx[{vec[1].F, vec[1].S}] << " ";
  cout <<  idx[{vec[pos].F, vec[pos].S}] << endl;


  return 0;
}