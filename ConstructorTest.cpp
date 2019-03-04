#include <bits/stdc++.h>
using namespace std;

#define MAXN (int) 1e5 + 2
#define MAXL 20
#define F first
#define S second
#define lli long long int
typedef pair<lli, pair<lli, lli> > iii;

struct teste{
  int a;
  int aa;

  bool operator=(const teste&b) {
    return a = b.a;
  }

  teste operator+(const teste&b){
    return {a+b.a, aa+b.aa};
  }
};

void coutt(teste a){
  cout << a.a << " - " << a.aa << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  teste a{1,2}, b{1,2};
  // a = {1, 2};
  // a.aa = 2;
  // b = {1, 2};
  // b.aa = 2;
  teste c = (a + b);
  coutt(c);


  return 0;
}