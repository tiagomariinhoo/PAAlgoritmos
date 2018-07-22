int phi(int a){
	int res = a;
	for(int p=2;p*p<=a;p++){
		if(a%p == 0){
			while(a%p == 0) a/=p;
			res -= res/p;
		}
	}
	if(a > 1) res -= res/a;
	return res;
}

/*
	Quantidade de coprimos que existem em 'a'
	Coprimos é gcd(a, x) == 1
*/