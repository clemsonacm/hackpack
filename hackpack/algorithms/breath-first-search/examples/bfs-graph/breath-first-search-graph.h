#include<cstdlib>
#include<list>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<fstream>
#include<string>

using namespace std;

ofstream output_file;

class Graph{
private:
	int GRAPH_SIZE;
	list<int> *adjacencyList;

	/** 
	 *  Helper method for BFS and DFS that checks whether
	 *  n is in the set or not 
	 */
	bool does_not_contain(set<int> set, int n){
		return set.find(n) == set.end();
	}

public:
 	/**
	 *  Instantiates a Graph object whose maximum number of vertices is 
     *  given by GRAPH_SIZE.
	 */
	Graph(int GRAPH_SIZE, const char *output_file_name){
		this->GRAPH_SIZE = GRAPH_SIZE;
		this->adjacencyList = new list<int>[GRAPH_SIZE];
		/* Clear the contents of the file by removing it */
        remove(output_file_name);
		/* Open the file */
        output_file.open(output_file_name, ofstream::out | ofstream::app);
	}

    ~Graph(){
		/* Close the file after the object is destroyed */
        if (output_file.is_open()){
            output_file.close();
        }
    }

	/** 
	 *	Adds an edge to the adjacency list. The vertex specifies the source
	 *	node and the edge specifies the destination node.
	 */
	void addEdge(int vertex, int edge){
		if (vertex > GRAPH_SIZE || edge > GRAPH_SIZE){
			throw "Cannot add values that exceed that graph's size: " 
				+ GRAPH_SIZE;
		}
		adjacencyList[vertex].push_back(edge);
	}

	/**
	 *  Executes breadth first search over the graph iteratively. The 
     *  algorithm traditionally uses a queue for the traversal. A set
     *  is used as the data structure for the visited list. Recall that
     *  each vertex should never be visited more than once. This is the
     *  purpose of the visitedSet.
     */
	void breadth_first_search(int start_vertex){
		if (start_vertex > GRAPH_SIZE){
			throw "Start vertex must not exceed graph's size: " + GRAPH_SIZE;
		}
		set<int> visitedSet;
		queue<int> q;
		list<int>::iterator it;
		q.push(start_vertex);
		visitedSet.insert(start_vertex);
        output_file << "Performing breadth first search on graph "
            "with start vertex = " << start_vertex << endl;
		while(!q.empty()){
			const int here=q.front();
			q.pop();
            output_file << here << " ";
			for(it=adjacencyList[here].begin(); it != adjacencyList[here].end(); it++){
				if(does_not_contain(visitedSet, *it)){
					visitedSet.insert(*it);
					q.push(*it);
				}
			}
		}
		output_file << endl;
	}

	/**
	 *  Executes depth first search over the graph iteratively. The 
     *  algorithm traditionally uses a stack for the traversal. A set
     *  is used as the data structure for the visited list.
     */
	
};
