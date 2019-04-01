#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define MAX 11000
#define MAXN 120
#define MIN -2000000
#define INF 0x3f3f3f3f
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> ii;
typedef pair<int, ii > iii;
#define F first
#define S second
vi vec;

//CORRETO
int lowerBound(int atual){
  int com = 0, fim = n-1;
  int ans = 0;
  while(com < fim){
    int mid = (com + fim) >> 1;
    if(atual <= vec[mid]) fim = mid;
    else com = mid + 1;
  }

  return com;
}

int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void bina(int x){
	int com = 0;
	int fim = sz(vec);
	int mid;

	while(com<fim){
		mid = (com + fim) / 2;

		if(vec[mid] == x){
			cout << "MId : " << mid << endl;
			return ;
		} else if(vec[mid] > x) fim = mid-1;
		else if (vec[mid] < x) com = mid + 1;
	}
	cout << "N achou!" << endl;
}

int main(){

	int a;
		cin >> a;
			for(int i=0;i<a;i++){
				int b;
					cin >> b;
						vec.pb(b);
			}
	sort(vec.begin(),vec.end());
	for(int i=0;i<sz(vec);i++)
		cout << vec[i] << " ";
	cout << endl;
	cin >> a;
	cout << "A : " << a << endl;
	cout << "-----" << endl;
	lower(a);
	cout << "-----" << endl;
	upper(a);
	cout << "-----" << endl;
	bina(a);

	return 0;
}