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

void invertBinaryTreeRecurisive(BinaryTree *tree)
{
	BinaryTree *l, *r, *curr = tree;
	if(curr)
	{
		l = curr->left?curr->left:NULL;
		r = curr->right?curr->right:NULL;
		curr->left = r;
		curr->right = l;

		if(curr->left)
			invertBinaryTreeRecursive(curr->left);
		if(curr->right)
			invertBinaryTreeRecursive(curr->right);
	}
}


void invertBinaryTreeIterative(BinaryTree *tree)
{
		BinaryTree *curr, *temp;
		queue<BinaryTree *> q;
		q.push(tree);
		while(!q.empty())
		{
				curr = q.front();
				q.pop();
				temp = curr->left;
				curr->left = curr->right;
				curr->right = temp;
				if(curr->left)
					q.push(curr->left);
				if(curr->right)
					q.push(curr->right);
		}
}

