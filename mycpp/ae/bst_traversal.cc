#include <vector>
using namespace std;

class BST 
{
	public:
		int value;
		BST *left;
		BST *right;

		BST(int val);
};

vector<int> inOrderTraverse(BST *tree, vector<int> array)
{
	if(!tree)
		return array;

	array = inOrderTraverse(tree->left, array);
	array.push_back(tree->value);
	array = inOrderTraverse(tree->right, array);
	return array;
}

vector<int> preOrderTraverse(BST *tree, vector<int> array)
{
	if(!tree)
		return array;

	array.push_back(tree->value);
	array = preOrderTraverse(tree->left, array);
	array = preOrderTraverse(tree->right, array);
	return array;
}

vector<int> postOrderTraverse(BST *tree, vector<int> array)
{
	if(!tree)
		return array;

	array = postOrderTraverse(tree->left, array);
	array = postOrderTraverse(tree->right, array);
	array.push_back(tree->value);
	return array;
}

