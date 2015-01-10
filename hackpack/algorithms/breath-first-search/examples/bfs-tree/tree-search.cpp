#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <queue>

using namespace std;

class BST{
private:
	int size;

	class Node{
		public:
			int n, xcoord, ycoord;
			Node *left, *right;
			Node(int n){
				this->n = n;
				left = right = NULL;
			}
			Node(int n, int xcoord, int ycoord){
				this->n = n;
				this->xcoord = xcoord;
				this->ycoord = ycoord;
				left = right = NULL;
			}
	};

	/* Insert helper method for inserting just inserting value */
	void insert(Node *here, int n){
		if(n < here->n){
			if(here->left == NULL){
				here->left = new Node(n);
			} 
			else{
				insert(here->left, n);
			}
		}
		else{
			if(here->right == NULL){
				here->right = new Node(n);
			} 
			else{
				insert(here->right, n);
			}
		}
	}

	/* Insert helper method for inserting value, xcoord and ycoord */
	void insert(Node *here, int n, xcoord, ycoord){
		if(n < here->n){
			if(here->left == NULL){
				here->left = new Node(n, xcoord, ycoord);
			} 
			else{
				insert(here->left, n);
			}
		}
		else{
			if(here->right == NULL){
				here->right = new Node(n, xcoord, ycoord);
			} 
			else{
				insert(here->right, n);
			}
		}
	}

public:
	Node *root;

	BST() {
		size = 0;
		root = NULL;
	}

	/* Insert only the value */
	void insert(int n){
		if(this->root == NULL){
			this->root = new Node(n);
		} 
		else{
			insert(this->root, n);
		}
	}

	/* Insert value and both coordinates */
	void insert(int n, int xcoord, int ycoord){
		if(this->root == NULL){
			this->root = new Node(n, xcoord, ycoord);
		} 
		else{
			insert(this->root, n, xcoord, ycoord);
		}
	}
	
	void breadth_first_traversal(){
		printf("breadth first traversal:\n");
		queue<Node *> q;
		q.push(this->root);
		while(q.size() != 0){
			Node *here = q.front();
			q.pop();
			Node *left_child = here->left;
			Node *right_child = here->right;
			if(left_child != NULL){
				printf("%d ", left_child->n);
				q.push(left_child);
			}
			if(right_child != NULL){
				printf("%d ", right_child->n);
				q.push(right_child);
			}
		}
		printf("\n");
	}
};

int main() {
	srand(time(NULL));
	BST bst;
	for (int i=1; i < 20; i++) {
		int random = rand() % 200;
		bst.insert(random);	
	}
	bst.preorder_traversal();
	bst.postorder_traversal();
	bst.inorder_traversal();
	bst.breadth_first_traversal();
}
