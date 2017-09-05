/* Floyd Warshal
	N MAX = 400
	Adj[i][j] contains the weight of edge (i, j)
	or INF (1B) if there is no such edge
 */
// remember loop is k->i-> j
for(int k = 0; k< N; k++)
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
/* parent matrix
	let p be a 2D parent matrix , where p[i][j] is the last vertex before j
	on shortest path from i to j
 */
// initialize the parent matrix
for(int i = 0; i<N; i++)
	for(int j = 0; j<N; j++)
		p[i][j] = i;

// floyd + update parent
for(int k = 0; k< N; k++)
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			if(adj[i][k]+adj[k][j] < adj[i][j]){
				adj[i][j] = adj[i][k]+adj[k][j];
				p[i][j] = p[k][j];
			}
// print the shortest path
void printPath(int i, int j){
	if(i != j)printPath(i, p[i][j]);
	printf(" %d", j);
}
/* Minimax and Maximin
	adj[i][j] is the weigth from i to j
*/
for(int k = 0; k < N; k++)
	for(int i = 0; i< N; i++)
		for(int j = 0 ; j< N; j++)
			adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));

/* Transitive Closure
Check if two vertex i j are directly or indirectly connected by checking adj[i][j]
where matrix adj contains true if i is directly connected to j or false otherwise
*/
for(int k = 0; k<N; k++)
	for(int i = 0; i<N; i++)
		for(int j = 0; j<N; j++)
			adj[i][j] |= (adj[i][k] & adj[k][j]);

		

