/*
Solution Notes (Jonathan Paulson): It's not obvious how to make the tradeoff between latency and capacity. 
But the graph is really small: only 500 edges. Even a quadratic algorithm will be fast enough.

Consider the optimal path. It has some minimum capacity C. The key observation is that if you throw out edges with capacity less than C, 
then the optimal path is just a shortest path. If only we knew C, we could just run Dijkstra.

But there are only M possible values for C (the minimum capacity of the optimal path is the capacity of its bottleneck edge, which is *some* edge). 
So we can just try all M values for C, run Dijkstra on each subgraph (of edges with capacity at least C), and take the best of these M paths 
(of course, if we choose a value if C so that the destination is not reachable, it can't have been right). 
Since Dijkstra is O(M log M), this idea is O(M^2 log M), which is fast enough. Here is Travis Hance's solution in C++:
*/


#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define NMAX 500
#define MMAX 500
#define infinite 1000000000000000000LL

struct edge {
    int dest;
    long long latency, cap;
    edge(int dest, long long latency, long long cap) :
        dest(dest), latency(latency), cap(cap) { }
};
vector<edge> edges[NMAX];
long long caps[MMAX];

struct entry {
    int v;
    long long dist;
    entry(int v, long long dist) : v(v), dist(dist) { }
    bool operator<(entry const& o) const {
        return dist > o.dist;
    }
};

bool visited[NMAX];
long long minL(int n, int source, int dest, int minCap) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    priority_queue<entry> q;
    q.push(entry(source, 0));
    while(q.size() > 0) {
        entry cur = q.top();
        q.pop();
        if (visited[cur.v]) {
            continue;
        }
        if (cur.v == dest) {
            return cur.dist;
        }
        visited[cur.v] = true;
        for (int i = 0; i < edges[cur.v].size(); i++) {
            edge e = edges[cur.v][i];
            if (e.cap >= minCap) {
                q.push(entry(e.dest, cur.dist + e.latency));
            }
        }
    }
    return infinite;
}

int main() {
    freopen("mroute.in","r",stdin);
    freopen("mroute.out","w",stdout);

    int n, m;
    long long X;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%lld", &X);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long l, c;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%lld", &l);
        scanf("%lld", &c);
        a--;
        b--;
        edges[a].push_back(edge(b, l, c));
        edges[b].push_back(edge(a, l, c));
        caps[i] = c;
    }

    long long mintime = infinite;
    for (int i = 0; i < m; i++) {
        long long c = caps[i];
        long long l = minL(n, 0, n-1, c);
        if (l != infinite) {
            mintime = min(mintime, l + X/c);
        }
    }
    printf("%lld\n", mintime);
}