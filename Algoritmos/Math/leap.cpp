bool leap(int yr){
	if(((yr % 4 == 0) && !(yr % 100 == 0))|| (yr % 400 == 0))	return true;
	else return false;
}