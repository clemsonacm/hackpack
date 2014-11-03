class Node{
	Node *left, *right,*parent;
	int key, size;
	public:
	Node(): left(0), right(0), parent(0), key(0), size(1) {};
	Node(int key): left(0), right(0), parent(0), key(key), size(1) {};
};
