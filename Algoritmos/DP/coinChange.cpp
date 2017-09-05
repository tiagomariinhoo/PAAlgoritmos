int value, coins;
int coin[MAX], change[MAX], WAY[MAX][MAX];
int ways(int vl, int type){
	if(vl == 0) return WAY[vl][type] = 1;
	if(vl < 0 || type == coins) return 0;
	if(WAY[vl][type] != -1) return WAY[vl][type];
	return WAY[vl][type] = (ways(vl, type+1) + ways(vl - coin[type], type));
}
int cc(int vl){
	if(change[vl] != -1) return change[vl];
	int ans = INT_MAX;
	for(int j = 0; j < coins; j++){
		if(vl < coin[j]) continue;
		ans = min (ans, cc(vl - coin[j]));
	}
	return change[vl] = 1 + ans;
}
int main(){
	cin >> value >> coins;
	for(int i = 0; i<coins ; i++)cin >> coin[i];
	memset(change, -1, sizeof change);
	memset(WAY, -1, sizeof WAY);
	printf("%d\n", ways(value, 0));
	change[0] = 0;
	printf("%d\n", cc(value));
}