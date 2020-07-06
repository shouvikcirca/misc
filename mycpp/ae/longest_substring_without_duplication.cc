#include<bits/stdc++.h>
using namespace std;

string longestSubstringWithoutDuplication(string str)
{
	unordered_map<char, int> dups;
	int start = 0;
	int end = 0;
	int ls = 0;
	int le = 0;
	
	while(end<str.length())
	{
		if(dups.count(str[end]))
		{
			if(le - ls < end - start)
			{
				ls = start;
				le = end;
			}
			start = dups.at(str[end])+1;
			end = start;
			dups.clear();
		}
		else
		{
			dups[str[end]] = end;
			end+=1;
		}
	}
	if(end-start > le - ls)
	{
			ls = start;
			le = end;
	}
  	return str.substr(ls,(le - ls));
}


int main()
{
	string s = "clementisacap";
	cout<<longestSubstringWithoutDuplication(s)<<endl;
}





