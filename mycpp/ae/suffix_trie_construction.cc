#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode
{
	public:
		unordered_map<char, TrieNode *> children;
};

class SuffixTrie
{
	public:
		TrieNode *root;
		char endSymbol;

		SuffixTrie(string str)
		{
			this->root = new TrieNode();
			this->endSymbol = '*';
			this->populateSuffixTrieFrom(str);
		}

		void populateSuffixTrieFrom(string str) 
		{
			char letter;

			for(int j=0;j<str.length();j++)
			{
				TrieNode *node = this->root;
				for(int i=j;i<str.length();i++)
				{
					letter = str[i];
					if(!node->children.count(letter))
					{
						TrieNode *newnode = new TrieNode();
						node->children[letter] = newnode;
						node = node->children[letter];
					}
					else
						node = node->children[letter];
				}
				node->children['*'] = NULL;
			}
		}

		bool contains(string str) 
		{
			TrieNode *start = this->root;
			for(int i=0;i<str.length();i++)
			{
				char letter = str[i];
				if(!start->children.count(letter))
					return false;
				else
					start = start->children[letter];
			}
			if(!start->children.count('*'))
				return false;
			else
				return true;
		}
};
