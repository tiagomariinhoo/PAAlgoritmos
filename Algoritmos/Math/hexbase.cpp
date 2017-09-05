string hexbase(long long num, long long b){
	string res;
	string d = "0123456789abcdef";
    while(num > 0){
        res = d[num % b] + res;
        num /= b;
    }
        return res;
}
long long todec(string num, int b){
	long long res = 0;
	int k = 1;
	for(int i = (int)num.size()-1; i >=0; --i){
		int dig = (num[i] >= 'a' && num[i] <= 'f')?num[i] -'a'+10:num[i] -'0';
		res+= dig*k;
		k*=b;
	}
	return res;
}