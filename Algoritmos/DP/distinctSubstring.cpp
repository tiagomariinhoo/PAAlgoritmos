int v[MAX], dp[MAX], l[500];
char sub[MAX], s[MAX], ss[MAX];;
const int mod = 1e9+7;
void solve(int tc){
	printf("Caso #%d:\n", tc);
	int m;
	scanf("%s %d", s+1, &m);
	for(int i = 0; i < m; i++){
		scanf("%s", ss+1);
		int jj = 1;
		int ans;
		int equal  = 0;
		for(int j =1 ; s[j]; j++){
			if(s[j] == ss[jj])jj++;
			if(ss[jj] == '\0'){
				ans = j;
				if(s[j+1] == '\0')equal = 1;
				break;
			}
		}
		if(equal){
			printf("1\n");
			continue;
		}
		if(ss[jj] != '\0')printf("0\n");
		else {
			memset(l, 0, sizeof l);
			int k;
			dp[ans] = 1;
	        for(int j = ans+1; s[j]; j++){
	            dp[j] = dp[j-1]*2;
	            if(l[s[j]])dp[j]-=dp[l[s[j]]-1];
	            l[s[j]] = j;
	            k = j;
	        }
	        printf("%d\n", dp[k]);
		}
	}

}