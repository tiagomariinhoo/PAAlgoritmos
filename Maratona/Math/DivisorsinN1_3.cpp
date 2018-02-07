
void crivo(int x, bool prime[], bool primesquare[], int aa[]){
	// bool primo[x+1];
	// bool primesquare[x+1];
	// int crivo[x];
	for(int i=2;i<=x;i++) prime[i] = true;
	for(int i=0;i<=(x*x+1);i++) primesquare[i] = false;

	prime[1] = false;
	for(int p = 2; p*p <= x;p++){
		if(prime[p] == true){
			 for(int i = p*2; i<= x; i += p) prime[i] = false;
		}
	}
	int j = 0;
	for(int p=2;p<=x;p++){
		if(prime[p]){
			aa[j] = p;
			primesquare[p*p] = true;
			j++;
		}
	}
}

int countDivisors(int x){
	if(pd[x]!=-1) return pd[x];
	if(x == 1) return 1;
	bool prime[x+1], primesquare[x*x+1];
	int aa[x];
	crivo(x, prime, primesquare, aa);
	int ans = 1;
	for(int i=0;;i++){
		if(aa[i]*aa[i]*aa[i] > x) break;
		int cnt = 1;
		while(x%aa[i]==0){
			x = x/aa[i];
			cnt = cnt+1;
		}
		ans = ans*cnt;
	}
	if(prime[x]) ans = ans*2;
	else if(primesquare[x]) ans = ans*3;
	else if(x != 1) ans = ans*4;
	return pd[x] = ans;
}