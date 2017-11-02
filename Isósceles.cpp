#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 50000
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
//g++ a.cpp -o a.exe && a.exe < in
int n;
int a[MAX], l[MAX], r[MAX];

int main (){
	cin >> n;
	l[0] = r[n-1] = 1;

		for(int i=0;i<n;i++)
			cin >> a[i];

		for(int i=1;i<n;i++)
			l[i] = min(a[i], l[i-1]+1);

		for(int i = n-1; i>=0; i--)
			r[i] = min(a[i],r[i+1]+1);

		for(int i=0;i<n;i++){
			cout << "l i : " << l[i] << " / " << "r i : " << r[i] << endl;
		}

		int ans = 1;
			for(int i=0;i<n;i++)
				ans = max(ans, min(l[i],r[i]));

			cout << ans << endl;

		return 0;
}