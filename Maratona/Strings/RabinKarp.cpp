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
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ddx[] = {1, 0};
int ddy[] = {1, 1};

#define d 256
vector<int> ans;

void rabinKarp(string txt, string pat, int q){
	int M = sz(pat);
	int N = sz(txt);
	int p = 0, t = 0, h = 1, j;

	if(M > N) return ;

	for(int i=0;i<M-1;i++){
		h = (h*d)%q;
	}

	for(int i=0;i<M;i++){
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}

	for(int i=0;i<=N-M;i++){
		if(p == t){
			for(j=0;j<M;j++){
				if(txt[i+j] != pat[j]) break;
			}

			if(j == M)
				ans.pb(i);			
		}

		if(i < (N - M)){
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			if(t < 0) t += q;
		}
	}
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	while(cin >> n){
		string a,b;
		cin >> a >> b;

		rabinKarp(b, a, 541);

		if(!sz(ans)) cout << endl;
		else {
			for(int i=0;i<sz(ans);i++) cout << ans[i] << endl;
		}	
		ans.clear();
	}


	return 0;
}

// _--- -- -- --- -- -- -- --- -

/* Following program is a C implementation of Rabin Karp
Algorithm given in the CLRS book */
#include<stdio.h>
#include<string.h>
 
// d is the number of characters in the input alphabet
#define d 256
 
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                printf("Pattern found at index %d \n", i);
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;
 
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
        }
    }
}
 
/* Driver program to test above function */
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}
