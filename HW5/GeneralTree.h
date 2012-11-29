#include <string>

using namespace std;

struct node {
	std::string name;
	int sons;
	node * first;
	node * next;
	bool visited;
};


class GeneralTree {
public:
	
	node * root;

	GeneralTree();
	void insert(node *&, string, string);
	void print_in_trav(node *);
	void in_trav(node *);

};

