#include<bits/stdc++.h>
using namespace std;

string underscorifySubstring(string str, string subStr) 
{
	vector<vector<int>> locs;
	vector<vector<int>> collapsedlocs;
	int pos=0;

	while(pos<=str.length()-1)
	{
		pos = str.find(subStr,pos);
		if(pos == string::npos)
			break;
		locs.push_back({pos,(int)(pos+subStr.length())});
		pos+=1;
	}

	collapsedlocs.push_back(locs[0]);
	for(int i=1;i<locs.size();i++)
	{
		if(locs[i][0]<=collapsedlocs.back()[1])
			collapsedlocs[collapsedlocs.size()-1][1] = locs[i][1];
		else
			collapsedlocs.push_back(locs[i]);
	}
	
	string ns = "";
	int stringindex = 0;
	int j;
	for(int i=0;i<collapsedlocs.size();i++)
	{
		j=0;
		while(j<2)
		{
			if(stringindex == collapsedlocs[i][j])
			{
				ns+="_";
				j+=1;
			}
			ns+=str[stringindex];
			stringindex+=1;

		}
	}

	while(stringindex<str.length())
	{
		ns+=str[stringindex];
		stringindex+=1;
	}

	return ns;
}



int main()
{
	string s = underscorifySubstring("abcabcabcabcabcabcabcabcabcabcabcabcabcabc","abc");
	cout<<s<<endl;
}

