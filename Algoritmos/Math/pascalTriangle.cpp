int c[MAX][MAX];
void pascalTriangle(){
	for(int i=0;i<MAX;i++) c[i][0] = 1, c[i][i] = 1;
	for(int i=1;i<MAX;i++) for(int j=1;j<i;j++) c[i][j] = c[i-1][j-1] + c[i-1][j];
}
