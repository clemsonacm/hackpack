#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<stack>
#include<queue>

#define MAX_N 10003
#define INFINITY 1 << 29;

using namespace std;

typedef pair<int, int> pii;

int N, M;

// va represents the original graph with GPS1's edge lengths
vector<pii> va[MAX_N];

// vb represents the original graph with GPS2's edge length
vector<pii> vb[MAX_N];

// vector v represents a new graph with edge lengths 0, 1, or 2 
// the edge lengths represent the number of complaints we get from 
// traversing that edge
vector<pii> v[MAX_N];

// 3 dimensional array to store distances for vectors va, vb and v
int dist[3][MAX_N];

// Dijkstra's shortest path algorithm
int dijkstra(vector<pii> v[MAX_N], int a, int src) {
	// initialize all distances to INFINITY
	for(int i = 0; i < MAX_N; i++) {
		dist[a][i] = INFINITY;
	}
	// source to source distance = 0
	dist[a][src] = 0;
	
	// initialize priority queue pq
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0, src));
	
	// calculate shortest path from source to all other nodes
	while (pq.size()) {
		int cur = pq.top().second;
		int dst = pq.top().first;
		// remove visited node
		pq.pop();
		// error check on distance
		if (dst != dist[a][cur]) {
			continue;
		}
		// for each path from current node, choose shortest path and place in pq
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int c = v[cur][i].second + dist[a][cur];
			if (c < dist[a][next]) {
				dist[a][next] = c;
				pq.push(pii(dist[a][next], next));
			}
		}
	}
	return dist[a][N - 1];
}

int main (void) {
  // open input and output files 
	freopen("gpsduel.in", "r", stdin);
	freopen("gpsduel.out", "w", stdout);
	
	// read in input and store into vectors va and vb
	// index corresponds to B_i, and pairs A_i with GPS length P_i or Q_i
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		// A_i and B_i are decremented to account for indexing starting at 0
		a--; b--; 
		va[b].push_back(pii(a, p));
		vb[b].push_back(pii(a, q));
	}
	
	// run dijkstra's on va and vb and store distances in dist array
	dijkstra(va, 0, N - 1);
	dijkstra(vb, 1, N - 1);
	
	// construct new graph 
	for (int cur = 0; cur < N; cur++) {
		for (int j = 0; j < va[cur].size(); j++) {
			int next = va[cur][j].first;
			// c represents edge length corresponding to number of complaints by GPS
			int c = 0;
			int dst1 = va[cur][j].second;
			int dst2 = vb[cur][j].second;
			// if dist[a] - dist[b] is the actual length of edge(a,b).
			// then edge(a, b) is part of shortest path, and GPS will not complain
			// else, add complaint to c
			if (dist[0][next] - dist[0][cur] != dst1) c++;
			if (dist[1][next] - dist[1][cur] != dst2) c++;
			v[next].push_back(pii(cur, c));
		}
	}

	// answer is shortest path or the least amount of complaints in new graph
	int answer = dijkstra(v, 2, 0);
	cout << answer << endl;

	return 0;
}
