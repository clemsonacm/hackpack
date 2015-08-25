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

bool dfs(Node& n, const unsigned int target)
{
	// Mark this node as visited.
	n.visited = true;
	if(n.hops_left > 0) n.hops_left--;

	// If we are currently visiting the node we have been looking
	// for, then the search is finished.
	if(n.id == target) return true;
	else
	{
		// Iterate through all neighbors of the current node and launch
		// a recursive search on each of them given that they haven't
		// been visited and, for this problem, are still traversable.
		for(vector<Node*>::iterator it = n.neighbors.begin();
				it != n.neighbors.end(); it++)
		{
			if(((*it)->hops_left < 0 || (*it)->hops_left > 0) && !(*it)->visited)
				if(dfs(**it, target)) return true; // A return value of true means the algorithm is complete.
		}
	}

	// Reset the state back to what it was to 'undo' the step.
	if(n.hops_left != -1) n.hops_left++;

	// Returns false if the node that's being search for cannot be
	// reached from this node.
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

	// Simulate the crossing of 'crossings' cows.
	for(unsigned int i = crossings; i > 0; i--)
	{
		if(!dfs(nodes[Start], nodes[Target].id))
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
