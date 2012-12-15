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
	void insert(node *, string, string, int);
	void print_in_trav(node *);
	void father_p(string);
	void sons_p(string);
	void brothers_p(string);
	void youngest_brother_p(string);
	void oldest_brother_p(string);
	void oldest_son_p(string);
	void youngest_son_p(string);
	void grandfather_p(string);
	void uncles_p(string);

private:
	void reset_visited(node *);
};

