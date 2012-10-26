struct Node {
	int num;
	Node * left;
	Node * right;
};

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree() {};
	void insert(int num);
	void PreTrav(Node * node);
	
private:
	void insertNode(Node * leaf, int num);
	Node * root;
};
