#include <cassert>
#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<unsigned int, unsigned int> Puiui;

struct Node
{
	unsigned int id;
	bool visited;
	unsigned int dist;
	vector<Node*> neighbors;

	Node() : id(0), visited(false), dist(0) {}
	Node(const unsigned int id) : id(id), visited(false), dist(0) {}
	~Node() {};
};

int main()
{
	Node* nodes = nullptr;
	vector<Puiui> edges;

	// Read in all edges.
	unsigned int a, b;
	unsigned int max_node_id = 0;
	while(cin >> a)
	{
		if(a > max_node_id) max_node_id = a;
		cin >> b;
		edges.push_back(make_pair(a, b));
	}

	// Make nodes.
	nodes = new Node[max_node_id + 1];
	assert(nodes);
	for(unsigned int i = 0; i <= max_node_id; i++)
		nodes[i].id = i;

	// Connect nodes by the specified edges.
	for(unsigned int i = 0; i < edges.size(); i++)
	{
		nodes[edges[i].first].neighbors.push_back(&nodes[edges[i].second]);
		nodes[edges[i].second].neighbors.push_back(&nodes[edges[i].first]);
	}

	// Breadth-first search from start to target.
	bool finished = false;
	const unsigned int Start = 0;
	const unsigned int Target = 20;

	queue<Node*> q;
	q.push(&nodes[0]);
	while(!q.empty() && !finished)
	{
		// Get current node.
		Node* current = q.front();
		q.pop();
		current->visited = true;

		// Update neighbors' distances.
		cout << "looking at node " << current->id << endl;;
		for(unsigned int i = 0; i < current->neighbors.size(); i++)
		{
			Node* neighbor = current->neighbors[i];
			cout << "looking at node neighbor " << neighbor->id << endl;
			if(neighbor->id == Target)
			{
				cout << "It will take " << neighbor->dist <<
					" hops to get to stone #" << neighbor->id << "." << endl;
				finished = true;
				break;
			}
			else if(!neighbor->visited)
			{
				q.push(neighbor);
				neighbor->dist = current->dist + 1;
			}
		}
	}

	delete[] nodes;

	return 0;
}
