#include <bits/stdc++.h>
using namespace std;

class Trie
{
	public:
		unordered_map<char, Trie*> um;
};


vector<bool> multiStringSearch(string bigString, vector<string> smallStrings)
{

	Trie *root = NULL;
	Trie *ptr;

	for(string str: smallStrings)
	{
		ptr = root;
		for(int j=0;j<str.length();j++)
		{
			if(!root)
			{
				root = new Trie();
				ptr = root;
				root->um[str[j]] = new Trie();
				ptr = ptr->um[str[j]];
			}
			else
			{
				if(ptr->um.count(str[j]))
					ptr = ptr->um[str[j]];
				else
				{
					ptr->um[str[j]] = new Trie();
					ptr = ptr->um[str[j]];
				}
			}
		}
		ptr->um['*'] = NULL;			
	}

	unordered_map<string,int> containedStrings;
	int j,start;
	string ns;

	for(int i=0;i<bigString.length();i++)
	{
		ptr = root;
		j = i;
		start = j;

		while(ptr->um.count(bigString[j]))
		{
			ptr = ptr->um[bigString[j]];
			j+=1;
			if(ptr->um.count('*'))
			{
				ns = bigString.substr(start,(j - start));
				containedStrings[ns] = 1;
			}
		}
	}

	vector<bool> yn;
	for(string i: smallStrings)
	{
		if(containedStrings.count(i))
			yn.push_back(true);
		else
			yn.push_back(false);
	}


	return yn;
}


int main()
{
	vector<bool> hasStrings;
	string bigString = "this is a big string";
	vector<string> smallStrings {"this", "yo","is","a","bigger","string","kappa"};
	hasStrings = multiStringSearch(bigString,smallStrings );

	cout<<bigString<<endl;
	for(int i=0;i<hasStrings.size();i++)
		cout<<smallStrings[i]<<":"<<hasStrings[i]<<endl;

	return 0;
}


