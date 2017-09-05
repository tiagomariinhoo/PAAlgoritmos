typedef vector<vector<long long> >matrix;
matrix mul(const matrix &A, const matrix &B){ // A*B
	matrix C(n, vector<long long>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C[i][j] = 0;
			for(int  k = 0; k < n; k++){
				C[i][j]+=A[i][k]*B[k][j];
 //if overflow  C[i][j]+= ((A[i][k]%mod)*(B[k][j]%mod))%mod
			}
			C[i][j]%=mod;
		}
	}
	return C;
}
matrix mpow(matrix &A, long long power){ // A ^ power
	int K = n;
	matrix iden(n, vector<long long>(n));
	for(int i = 0; i < K; i++)
		for(int j = 0; j < K; j++)iden[i][j] = (i == j);
	while(power){
		if(power&1) iden = mul(iden, A);
		A = mul(A, A);
		power >>= 1;
	}
	return iden;
}
/////////////////////////////////////////////////////////////
