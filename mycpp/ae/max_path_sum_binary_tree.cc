#include<bits/stdc++.h>
using namespace std;

class BinaryTree
{
	public:
		int value;
		BinaryTree *left;
		BinaryTree *right;

		BinaryTree(int value);
		void insert(vector<int> values, int i = 0);
};

vector<int> maxSum(BinaryTree *tree)
{
	if(!tree)
		return {0,INT_MIN};

	vector<int> leftdata;
	leftdata = maxSum(tree->left);

	vector<int> rightdata;
	rightdata = maxSum(tree->right);

	int maxbranchsum = max(leftdata[0], rightdata[0]);
	int mayberootsum = max(maxbranchsum+tree->value, tree->value);
	int maybetrianglesum = max(mayberootsum, (leftdata[0]+tree->value+rightdata[0]));
	int largestsum = max(leftdata[1]>rightdata[1]?leftdata[1]:rightdata[1], maybetrianglesum);

	return {mayberootsum, largestsum};		
}

int maxPathSum(BinaryTree tree)
{
	vector<int> sums = maxSum(&tree);
	return sums[1];	
}


