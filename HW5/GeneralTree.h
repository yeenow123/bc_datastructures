#include <string>

using namespace std;

struct node {
	std::string name;
	int sons;
	bool visited;
	node * first;
	node * next;
	node * parent;
	
};

class GeneralTree {
public:
	
	node * root;

	GeneralTree();
	void insert(node *, string, string);
	void print_in_trav(node *);
	void father_p(string);

private:
	void reset_visited(node *);
};

