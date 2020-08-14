#include <vector>
using namespace std;

class BinaryTree {
	public:
		int value;
		BinaryTree *left;
		BinaryTree *right;

		BinaryTree(int value);
		void insert(vector<int> values, int i = 0);
		void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree)
{
	BinaryTree *l, *r, *curr = tree;
	if(curr)
	{
		l = curr->left?curr->left:NULL;
		r = curr->right?curr->right:NULL;
		curr->left = r;
		curr->right = l;

		if(curr->left)
			invertBinaryTree(curr->left);
		if(curr->right)
			invertBinaryTree(curr->right);
	}
}
