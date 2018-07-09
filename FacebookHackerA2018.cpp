#include <bits/stdc++.h>
using namespace std;
 
#define DEBUG if(1)
#define MAXN 100
#define MAX INT_MAX
#define MAXLL INT_MAX
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<string, pair<int, char> > ps;
#define DEBUG if(1)
#define F first
#define S second
// int dx[] = {0, 1, 0, -1};
// int dy[] = {1, 0, -1, 0};
// int ddx[] = {1, 0};
// int ddy[] = {1, 1};

lli t, k , n, v;
int aa = 0;
vector<int> ans[51];

void combinationUtil(int arr[], int data[], int start, int end, 
                     int index, int r);

void printCombination(int arr[], int n, int r)
{
    int data[r];
 
    combinationUtil(arr, data, 0, n-1, 0, r);
}
 
void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r)
{
    if (index == r)
    {
        for (int j=0; j<r; j++)
        	ans[aa].pb(data[j]);

        aa++;
        return;
    }

    for (int i=start; i<=end && end-i+1 >= r-index; i++){
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	int tt = 1;

	while(tt <= t){
		cin >> n >> k >> v;
		for(int i=0;i<=50;i++) ans[i].clear();
		vector<string> vec;
		aa = 0;
		for(int i=0;i<n;i++){
			string s;
			cin >> s;
			vec.pb(s);
		}

		int aux[51];
		for(int i=1;i<=n;i++){
			aux[i-1] = i;
		}

		printCombination(aux, n, k);

		for(int i=0;i<aa;i++){
			for(auto j : ans[i]) cout << j << " ";
				cout << endl;
		}

		cout << aa << endl;
		cout << "Case " << "#" << tt++ << ": ";
		// for(auto j : ans[(v-1)%aa]) cout << vec[j-1] << " ";
			// cout << endl;
		cout << tt++ << endl;
	}


	return 0;
}