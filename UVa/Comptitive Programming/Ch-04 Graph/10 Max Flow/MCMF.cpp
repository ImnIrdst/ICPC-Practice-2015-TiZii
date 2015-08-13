MCMF USING DIJKSTRA (O(E*LOG(E)*MAXFLOW) )
/*fnet contains the flow network. Careful: both fnet[u][v] andfnet[v][u] could be positive.**/
#define NN 1024
int cap[NN][NN], cost[NN][NN], fnet[NN][NN], adj[NN][NN], deg[NN];
int par[NN], d[NN], q[NN], inq[NN], qs, pi[NN];
#define CLR(a, x) memset( a, x, sizeof( a ) )
#define Inf (INT_MAX/2)
#define BUBL { t = q[i]; q[i] = q[j]; q[j] = t; t = inq[q[i]]; inq[q[i]] = inq[q[j]]; inq[q[j]] = t; }
#define Pot(u,v) (d[u] + pi[u] - pi[v])
bool dijkstra( intn, ints, intt ){
	CLR( d, 0x3F ); CLR( par, -1 ); CLR( inq, -1 );
	d[s] = qs = 0; inq[q[qs++] = s] = 0; par[s] = n;
	while( qs ){
		int u = q[0]; inq[u] = -1; q[0] = q[--qs];
		if( qs ) inq[q[0]] = 0;
		for( int i = 0, j = 2*i + 1, t; j < qs; i = j, j = 2*i + 1 ){
			if( j + 1 < qs && d[q[j + 1]] < d[q[j]] ) j++;			
			if( d[q[j]] >= d[q[i]] ) break;
			BUBL;
		}
		for(int k = 0, v =adj[u][k]; k<deg[u]; v = adj[u][++k] ){
			if( fnet[v][u] && d[v] >Pot(u,v) - cost[v][u] )
				d[v] = Pot(u,v) - cost[v][par[v] = u];
			if( fnet[u][v] < cap[u][v] && d[v] >Pot(u,v) + cost[u][v] )
				d[v] = Pot(u,v) + cost[par[v] = u][v];
			if( par[v] == u ){
				if( inq[v] < 0 ) { inq[q[qs] = v] = qs; qs++; }
				for( int i = inq[v], j = ( i - 1 )/2, t;
					d[q[i]] < d[q[j]]; i = j, j = ( i - 1 )/2 )
				BUBL;
	}	}	}
	for( int i = 0; i <n; i++ ) if( pi[i] <Inf ) pi[i] += d[i];
	return par[t] >= 0; }
int mcmf4( intn, ints, intt, int&fcost ){
	CLR( deg, 0 );
	for( int i = 0; i <n; i++ ) for( int j = 0; j <n; j++ )
			if( cap[i][j] || cap[j][i] ) adj[i][deg[i]++] = j;
	CLR( fnet, 0 ); CLR( pi, 0 );
	int flow = fcost = 0;
	while( dijkstra( n, s, t ) ){
		int bot = INT_MAX;
		for( int v = t, u = par[v]; v != s; u = par[v = u] )
			bot <= fnet[v][u] ? fnet[v][u] : ( cap[u][v] - fnet[u][v] );
		for( int v = t, u = par[v]; v != s; u = par[v = u] )
			if( fnet[v][u] ) { fnet[v][u] -= bot; fcost -= bot * cost[v][u]; }
			else { fnet[u][v] += bot; fcost += bot * cost[u][v]; }
		flow += bot;
	}
	return flow;
}
int main(){
	int numV, m, a, b, c, cp, s, t;
	memset( cap, 0, sizeof( cap ) );
	cin >> numV;	cin >> m>> s >> t;		
	for (int i=0; i<m; i++) {
		cin >> a >> b >> cp >> c;
		cost[a][b] = c; // cost[b][a] = c;
		cap[a][b] = cp; // cap[b][a] = cp;
	}
	int fcost;
	int flow = mcmf4( numV, s, t, fcost );
	cout <<"flow: "<< flow  <<" cost: "<< fcost << endl;
}
