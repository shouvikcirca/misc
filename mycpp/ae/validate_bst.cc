class BST 
{
	public:
		int value;
		BST *left;
		BST *right;

		BST(int  val);
		BST &insert(int val);
};



bool checkValidity(BST *tree, int minval, int maxval)
{
	if(tree->value<minval || tree->value>=maxval) 
		return false;

	if(!tree->left && !tree->right)
		return true;

	bool l = tree->left?checkValidity(tree->left,minval,tree->value):true;
	bool r = tree->right?checkValidity(tree->right,tree->value, maxval):true;
	return l&&r;
} 

bool validateBst(BST *tree)
{
	return checkValidity(tree,INT_MIN, INT_MAX);		
}

