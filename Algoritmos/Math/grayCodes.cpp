unsigned int binaryToGray(unsigned int num){
	return num ^ (num >> 1);
}
unsigned int grayToBinary(unsigned int num){
	int k = 16;
	while(k){	
		num^=(num >> k);
		k = (k >> 1);
	}
    return num;
}