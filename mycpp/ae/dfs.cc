#include <vector>
using namespace std;

class Node {
	public:
		string name;
		vector<Node *> children;

		Node(string str) { name = str; }

		void dfs(vector<string> *array, Node *n)
		{
			array->push_back(n->name);
			for(Node* p:n->children)
				dfs(array, p);
		}

		vector<string> depthFirstSearch(vector<string> *array)
		{
			Node *n = this;
			this->dfs(array, n);
			return *array;
		}

		Node *addChild(string name)
	       	{
			Node *child = new Node(name);
			children.push_back(child);
			return this;
		}
};
