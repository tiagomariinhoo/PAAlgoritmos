#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100001
#define MIN -2000000
#define INF (int)1e9
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
//g++ sol.cpp -std=c++11 -o sol.exe && sol.exe < in.txt
/* LowerBound and UpperBound iterator
*/

int n;

vi vec;
void lowerB(int v){
	vector<int>::iterator it;
	it = lower_bound(vec.begin(), vec.end(), v);

	cout << "Lower - Posicao de " << v << endl; 
	cout << it - vec.begin() << endl;

}
void upperB(int v){
	vector<int>::iterator it;
	it = upper_bound(vec.begin(), vec.end(), v);

	cout << "Upper - Poiscao de " << v << endl;
	cout << (it - vec.begin()) + 1 << endl;
}

int main(){
	
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
			cin >> a;
				vec.pb(a);
	}
	sort(vec.begin(), vec.end());

	lowerB(3);
	upperB(3);

	return 0;
}