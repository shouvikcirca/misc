#include <vector>
using namespace std;

class BST {
	public:
		int value;
		BST *left;
		BST *right;

		BST(int val) {
			value = val;
			left = NULL;
			right = NULL;
		}

		BST &insert(int val)
		{
			BST *ptr = this;
			int f = 1;
			while(f)
			{
				if(ptr->value<=val)
				{
					if(ptr->right)
						ptr=ptr->right;
					else
					{
						ptr->right = new BST(val);
						f = 0;
					}
				}
				else if(ptr->value>val)
				{
					if(ptr->left)
						ptr = ptr->left;
					else
					{
						ptr->left = new BST(val);
						f = 0;
					}
				}
			}
			return *this;
		}

		bool contains(int val)
		{
			BST *ptr = this;
			while(ptr)
			{
				if(ptr->value == val)
					return true;
				else if(ptr->value<=val)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			return false;
		}

		BST &remove(int val) 
		{
			if((!this->left && !this->right))
				return *this;

			int dir = -1;
			BST *ptr = this, *prev;

			while(ptr && ptr->value !=val)
			{
				if(ptr->right && val>= ptr->value)
				{
					dir=1;
					prev = ptr;
					ptr = ptr->right;
				}
				else if(ptr->left and val<ptr->value)
				{
					dir=2;
					prev = ptr;
					ptr = ptr->left;
				}
				else
					break;
			}

			if(!ptr->left && !ptr->right)
			{
				if(dir == 1)
					prev->right = NULL;
				else if(dir == 2)
					prev->left = NULL;
			}

			BST *replaceNode = ptr;

			if(ptr->right)
			{
				ptr=ptr->right;
				if(ptr->left)
				{
					while(ptr->left->left)
						ptr=ptr->left;
					replaceNode->value = ptr->left->value;
					ptr->left = NULL;
				}
				else
				{
					replaceNode->value = ptr->value;
					replaceNode->right = ptr->right;
				}

			}
			else if(ptr->left)
			{
				ptr=ptr->left;
				if(ptr->right)
				{
					while(ptr->right->right)
						ptr=ptr->right;
					replaceNode->value = ptr->right->value;
					ptr->right = NULL;
				}
				else
				{
					replaceNode->value = ptr->value;
					replaceNode->left = ptr->left;
				}
			}
			return *this;
		}
};
