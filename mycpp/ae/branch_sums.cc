using namespace std;

// This is the class of the input root. Do not edit it.
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


vector<int> returnSum(int sum, BinaryTree *root)
{
	vector<int> leftarray;
	vector<int> rightarray;

	if(!root->left && !root->right)
	{
		sum+=(root->value);
		leftarray.push_back(sum);
		return leftarray;
	}

	leftarray = root->left?returnSum(sum+root->value, root->left):leftarray;
	rightarray = root->right?returnSum(sum+root->value, root->right):rightarray;


	if(!leftarray.empty() && !rightarray.empty())
	{
		for(int i = 0;i<rightarray.size();i++)
			leftarray.push_back(rightarray[i]);
		return leftarray;
	}
	else if(leftarray.empty())
		return rightarray;
	else
		return leftarray;


}

vector<int> branchSums(BinaryTree *root)
{

	if(!root)
		return {};
	return returnSum(0, root);
}





