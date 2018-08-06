#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 1000100
#define MIN -2000000
#define INF (1<<30)
#define MOD 1000000007
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
#define rep(i,a,n) for (int i=a;i<n;i++)
#define ler(a,n,vec) for(int i=0;i<n;i++)s(a), vec.pb(a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define F first
#define S second
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

string s,aux;

int main(){

	cin >> s;

	// int n = atoi(aux.c_str());
	if(s.size()==2){
		int n = (int) s[0] - '0';
		int b = (int) s[1] - '0';
		if((n*10+b)%8==0){
			cout << "YES" << endl;
			cout << n*10 + b << endl;
		} else if(n%8==0) cout << "YES" << endl << n << endl;
		else if(b%8==0) cout << "YES" << endl << b << endl;
		else cout << "NO" << endl;
		// cout << n << " - " << b << endl;
		return 0;
	} else if (s.size()==1){
		int n = (int) s[0] - '0';
		if(n%8==0) cout << "YES" << endl << n << endl;
		else cout << "NO" << endl;
		return 0;
	}
	
	// int i = s.size()-1;
	// int j = s.size()-2;
	// int k = s.size()-3;
			
		// int n = atoi(aux.c_str());

		for(int i=0;i<s.size();i++){
			for(int j=i+1;j<s.size();j++){
				for(int k=j+1;k<s.size();k++){
					int a = (int) s[i] - '0';
					int b = (int) s[j] - '0';
					int c = (int) s[k] - '0';
					// cout << a << " - " << b << " - " << c << endl;
					if(a%8==0){
						cout << "YES" << endl;
						cout << a << endl;
						return 0;
					} else if(b%8==0){
						cout << "YES" << endl;
						cout << b << endl;
						return 0;
					} else if(c%8==0){
						cout << "YES" << endl;
						cout << c << endl;
						return 0;
					} else if((a*10+b)%8==0){
						cout << "YES" << endl;
						cout << a*10 + b << endl;
						return 0;
					} else if((a*10+c)%8==0){
						cout << "YES" << endl;
						cout << a*10 + c << endl;
						return 0;
					} else if((b*10+c)%8==0){
						cout << "YES" << endl;
						cout << b*10 + c << endl;
						return 0;
					} else if((a*100 + b*10 + c)%8==0){
						cout << "YES" << endl;
						cout << a*100 + b*10 + c << endl;
						return 0;
					}
				}
			}
		}
		// cout << n << endl;
	

	cout << "NO" << endl;
	// cout << n << endl;



	return 0;
}