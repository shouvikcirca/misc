using namespace std;

class BinaryTree {
	public:
		int value;
		BinaryTree *left;
		BinaryTree *right;

		BinaryTree(int value) {
			this->value = value;
			left = NULL;
			right = NULL;
		}
};

int depths(BinaryTree *root, int d)
{
	return root?( d + (root->left?depths(root->left, d+1):0) + (root->right?depths(root->right, d+1):0) ):0;
}



int nodeDepths(BinaryTree *root) 
{
	return depths(root, 0);
	return -1;
}


