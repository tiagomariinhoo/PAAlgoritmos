bool retInRet(int a, int b, int p, int q){
	if(a < b)swap(a, b);
	if(p < q)swap(p, q);
	if((p<=a && q<=b) || (p >a && b>= (2*p*q*a+((p*p - q*q))*sqrt(p*p+q*q-a*a))/(p*p+q*q)))return true;
	else{
		swap(a, p);
		swap(b, q);
		if((p<=a && q<=b) || (p >a && b>= (2*p*q*a+((p*p - q*q))*sqrt(p*p+q*q-a*a))/(p*p+q*q)))return true;
		return false;
	}
}