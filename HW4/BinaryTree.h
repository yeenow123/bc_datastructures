struct Node {
	int num;
	Node * left;
	Node * right;
};

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree() {};	

	void insert(int);
	void remove(int);
	void PreTrav(Node *);
	void InTrav(Node *);
	void PostTrav(Node *);
	int nodeCount(Node *);
	void childrenCount(Node *);
	
	Node * root;
private:
	void insertNode(Node *, int);
	void removeNode(Node *&);
};
