#include <vector>
#include "binary_tree_with_parent_prototype.h"
#include "test_framework/generic_test.h"

using std::vector;

vector<int> InorderTraversal(const unique_ptr<BinaryTreeNode<int>>& tree)
{
	BinaryTreeNode<int>*prev = nullptr, *curr = tree.get(), *next;
 	vector<int> result;
 	while(curr!=NULL)
  	{
      		if(curr->parent == prev)
      		{
          		if(curr->left.get())
              			next = curr->left.get();
          		else
          		{
              			result.emplace_back(curr->data);
              			if (curr->right.get())
                  			next = curr->right.get();
              			else
                  			next = curr->parent;
          		}
      		}	
      		else if(curr->left.get() == prev)
      		{
          		result.emplace_back(curr->data);
          		if(curr->right.get())
              			next = curr->right.get();
          		else
              			next = curr->parent;
      		}
      		else
          		next = curr->parent;

      		prev = curr;
      		curr = next;
  	}
  	return result;
}

int main(int argc, char* argv[])
{
 	std::vector<std::string> args{argv + 1, argv + argc};
  	std::vector<std::string> param_names{"tree"};
  	return GenericTestMain(args, "tree_with_parent_inorder.cc","tree_with_parent_inorder.tsv", &InorderTraversal,DefaultComparator{}, param_names);
}








