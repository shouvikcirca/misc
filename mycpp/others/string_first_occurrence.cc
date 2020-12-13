//string_first_occurrence.cc
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s = "eabcdef";
	string x = "*cdef";

	vector<int> indices;

	for(int i=0;i<s.length();i++)
	{
		if(s.at(i) == x.at(0))
			indices.push_back(i);
	}
	
	int start;
	int xindex;
	int ans = -1;

	for(int i=0;i<indices.size();i++)
	{
		start = indices[i];
		xindex = 0;
		for(int j=start;j<start+x.length();j++)
		{
			if( (s.at(j) != x.at(xindex)) && (x.at(xindex) != '*' ))
				break;
			xindex+=1;
		}

		if(xindex == x.length())
		{
			ans = start;
			break;
		}
	}


	cout<<ans<<endl;

}
