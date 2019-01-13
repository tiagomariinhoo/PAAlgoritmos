int fun(int x){
	if(pd[x] != -1) return pd[x];
	int ans = 0;
	vi v;
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			if(x/i == i) ans++;
			else ans++, v.pb(x/i);
		}
	}
	for(int i = sz(v)-1;i>=0;i--) ans++;
	// for(int i=1;i<=x;i++) if(x%i==0) ans++;
	// cout << x << " - " << ans << endl;
	return pd[x] = ans;
}

void printDivisors(int n) 
{ 
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                printf("%d ", i); 
  
            else // Otherwise print both 
                printf("%d %d ", i, n/i); 
        } 
    } 
} 