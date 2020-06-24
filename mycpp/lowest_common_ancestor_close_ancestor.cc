#include <memory>
#include <stdexcept>
#include <unordered_set>

#include "binary_tree_with_parent_prototype.h"
#include "test_framework/binary_tree_utils.h"
#include "test_framework/generic_test.h"
#include "test_framework/test_failure.h"
#include "test_framework/timed_executor.h"

using std::invalid_argument;
using std::unique_ptr;
using std::unordered_set;

BinaryTreeNode<int>* Lca(const unique_ptr<BinaryTreeNode<int>>& node0, const unique_ptr<BinaryTreeNode<int>>& node1)
{
	BinaryTreeNode<int>*iter0 = node0.get(), *iter1 = node1.get();

    	unordered_set<const BinaryTreeNode<int>*> pathnodes;
    	while(iter0 || iter1)
    	{
        	if(iter0)
        	{
            		if (pathnodes.count(iter0))
                		return iter0;
            		else
                		pathnodes.emplace(iter0);
            		iter0 = iter0->parent?iter0->parent:nullptr;
        	}
        	if(iter1)
        	{
            		if (pathnodes.count(iter1))
                		return iter1;
            		else
                		pathnodes.emplace(iter1);
            		iter1 = iter1->parent?iter1->parent:nullptr;
        	}

    	}

}

int LcaWrapper(TimedExecutor& executor,
               const unique_ptr<BinaryTreeNode<int>>& tree, int key0,
               int key1) {
  const unique_ptr<BinaryTreeNode<int>>& node0 = MustFindNode(tree, key0);
  const unique_ptr<BinaryTreeNode<int>>& node1 = MustFindNode(tree, key1);

  auto result = executor.Run([&] { return Lca(node0, node1); });

  if (!result) {
    throw TestFailure("Result can not be nullptr");
  }
  return result->data;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "tree", "key0", "key1"};
  return GenericTestMain(args, "lowest_common_ancestor_close_ancestor.cc",
                         "lowest_common_ancestor.tsv", &LcaWrapper,
                         DefaultComparator{}, param_names);
}
