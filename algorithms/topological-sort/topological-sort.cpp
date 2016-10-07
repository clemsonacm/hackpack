#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Node
{
    bool visited;
    set<Node*> incoming;
    set<Node*> outgoing;
    int id;
};

void connect(Node* a, Node* b)
{
    a->outgoing.insert(b);
    b->incoming.insert(a);

    return;
}

int main()
{
    vector<Node*> start;
    vector<Node*> graph;

    Node all[5];
    for(int i = 0; i < 5; i++)
    {
	all[i].visited = false;
	all[i].id = i;
	graph.push_back(&all[i]);
    }

    connect(&all[1], &all[0]);
    connect(&all[2], &all[1]);
    connect(&all[2], &all[3]);
    connect(&all[3], &all[4]);

    // Add all graph without incoming edges.
    for(vector<Node*>::iterator it = graph.begin(); it != graph.end(); it++)
    {
	if((*it)->incoming.size() == 0)
	    start.push_back(*it);
    }

    // Sort topologically.
    vector<Node*> ordering;
    while(start.size() > 0)
    {
	Node* const n = start.back();
	start.pop_back();

	ordering.push_back(n);

	// Remove edge.
	for(set<Node*>::iterator it = n->outgoing.begin(); it != n->outgoing.end();)
	{
	    (*it)->incoming.erase(n);
	    if((*it)->incoming.size() == 0)
		start.push_back((*it));
	    it = n->outgoing.erase(it);
	}
    }

    // Check for edges.
    for(vector<Node*>::iterator it = graph.begin(); it != graph.end(); it++)
    {
	if((*it)->outgoing.size() > 0)
	{
	    cout << "This graph has cycles." << endl;
	    return 1;
	}
    }

    for(vector<Node*>::iterator it = ordering.begin(); it != ordering.end(); it++)
    {
	cout << (*it)->id << " ";
    }
    cout << endl;

    return 0;
}
