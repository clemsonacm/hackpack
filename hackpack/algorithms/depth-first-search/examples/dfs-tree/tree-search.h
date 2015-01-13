#include <cstdlib>
#include <cstdio>
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
	void insert(Node *here, int n, int xcoord, int ycoord){
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

	/* Depth-first traversals include preoder, postorder and inorder */
	void preorder(Node *here){
		if(here != NULL){
			printf("%d ", here->n);
			preorder(here->left);
			preorder(here->right);
		}		
	}
	void postorder(Node *here){
		if(here != NULL){
			postorder(here->left);
			postorder(here->right);
			printf("%d ", here->n);
		}		
	}
	void inorder(Node *here){
		if(here != NULL){
			inorder(here->left);
			printf("%d ", here->n);
			inorder(here->right);
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

	void preorder_traversal(){
		printf("preorder traversal:\n");
		preorder(this->root);
		printf("\n");
	}

	void postorder_traversal(){
		printf("postorder traversal:\n");
		postorder(this->root);
		printf("\n");
	}

	void inorder_traversal(){
		printf("inorder traversal:\n");
		inorder(this->root);
		printf("\n");
	}
	
};

