int dp[MAX][MAX];
int main(){
	string s, t;
	int n, m;
	while(getline(cin, s)){
		getline(cin, t);
		n = s.size(), m = t.size();
		int ans = 0;
		for(int i = 0; i < n; i++)for(int j = 0; j < m; j++){
			if(s[i] == t[j]){
				if(i == 0 || j == 0)dp[i][j] = 1;
				else dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
			}else dp[i][j] = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}
