struct Node {
	int num;
	Node * left;
	Node * right;
};

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree() {};	

	void insert(Node *&, int);
	void remove(int);
	void PreTrav(Node *);
	void InTrav(Node *);
	void PostTrav(Node *);
	int nodeCount(Node *);
	void childrenCount(Node *);
	void deleteTree(Node *);
	
	Node * root;
private:
	//void insertNode(Node *&, int);
	void removeNode(Node *&);
};
