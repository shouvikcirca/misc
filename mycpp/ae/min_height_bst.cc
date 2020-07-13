using namespace std;

class BST
{
	public:
		int value;
		BST *left;
		BST *right;

		BST(int value)
		{
			this->value = value;
			left = NULL;
			right = NULL;
		}

};


BST* constructTree(int start, int end, vector<int> array, BST *root  , int l)
{

	BST *troot;
	if((end<start) ||(!root & array.empty()))
		return NULL;

	int mid = (start+end)/2;

	if(start == end)
	{
		if(!root)
			root = new BST(array[mid]); 
		else if(!l)
			root->left = new BST(array[mid]);
		else
			root->right = new BST(array[mid]);
		return root;
	}

	if(!root)
	{
		root = new BST(array[mid]);
		troot = root;
	}
	else if(!l)
	{
		root->left = new BST(array[mid]);
		troot = root->left;
	}
	else
	{
		root->right = new BST(array[mid]);
		troot = root->right;
	}

	BST *left = constructTree(start,mid-1,array,troot,0);
	BST *right = constructTree(mid+1,end,array,troot,1);
	return root;
}



BST *minHeightBst(vector<int> array)
{
	BST *root = NULL;
	root = constructTree(0,array.size()-1,array, root, -1);
	return root;
}





