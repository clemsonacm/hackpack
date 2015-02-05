#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	bool visited;
	unsigned int id;
	int hops_left;
	vector<Node*> neighbors;

	Node() : visited(false), id(0), hops_left(-1) {}
};

bool bfs(Node& n, const unsigned int target)
{
	n.visited = true;
	if(n.hops_left > 0) n.hops_left--;

	if(n.id == target) return true;
	else
	{
		for(vector<Node*>::iterator it = n.neighbors.begin();
				it != n.neighbors.end(); it++)
		{
			if(((*it)->hops_left < 0 || (*it)->hops_left > 0) && !(*it)->visited)
				if(bfs(**it, target)) return true;
		}
	}

	return false;
}

int main()
{
	unsigned int a, b;
	unsigned int node_count;
	Node* nodes = nullptr;

	// Get number of crossings.
	cin >> a;
	const unsigned int crossings = a;

	// Create Node array.
	cin >> node_count;
	nodes = new Node[node_count];
	assert(nodes);
	for(unsigned int i = 0; i < node_count; i++)
		nodes[i].id = i;

	cin >> a >> b;
	const unsigned int Start = a;
	const unsigned int Target = b;

	// Apply constraints
	unsigned int constrained_nodes;
	cin >> constrained_nodes;
	for(unsigned int i = 0; i < constrained_nodes; i++)
	{
		cin >> a >> b;
		nodes[a].hops_left = b;
	}

	// Read and connect edges.
	while(cin >> a >> b)
	{
		nodes[a].neighbors.push_back(&nodes[b]);
		nodes[b].neighbors.push_back(&nodes[a]);
	}

	for(unsigned int i = crossings; i > 0; i--)
	{
		if(!bfs(nodes[Start], nodes[Target].id))
		{
			cout << "It is not possible. Only " << crossings - i << " can cross." << endl;
			return 0;
		}

		// Reset visited status.
		for(unsigned int i = 0; i < node_count; i++)
			nodes[i].visited = false;
	}

	cout << "It is possible." << endl;

	delete[] nodes;

	return 0;
}
