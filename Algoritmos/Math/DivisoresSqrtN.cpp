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