class BST {
	public:
		int value;
		BST *left;
		BST *right;

		BST(int val);
		BST &insert(int val);
};

int findMin(BST *tree, int target, int minel)
{
	if(abs(target - tree->value) < abs(target - minel))
		minel = tree->value;

	if(tree->value < target)
	{
		if(tree->right)
			return(findMin(tree->right, target, minel));
		else
			return minel;
	}
	else if(tree->value > target)
	{
		if(tree->left)
			return(findMin(tree->left, target, minel));
		else
			return minel;
	}
	else
		return minel;
}	

int findClosestValueInBst(BST *tree, int target)
{
	return tree?findMin(tree, target, tree->value):-1;
}
