#include<bits/stdc++.h>
using namespace std;

vector<string> checkValidity(int xlength, int ylength, string str, string pattern, char inverted)
{
	unordered_map<string,string> um;
	int strind = 0, patternind = 0;
	while(strind<str.length() && patternind<pattern.length())
	{
		if(pattern[patternind] == 'x')
		{
			um[str.substr(strind,xlength)] = "x";
			strind+=xlength;
		}

		else
		{
			um[str.substr(strind,ylength)] = "y";
			strind+=ylength;
		}

		patternind+=1;

	}

	vector<string> returnwords;	

	if(um.size()!=2)
		return returnwords;
	
	string f="x",s="y";
	if(inverted)
	{
		f = "y";
		s = "x";
	}
	

		for(auto i:um)
		{
			if(i.second == s)
				returnwords.push_back(i.first);
			else
				returnwords.insert(returnwords.begin(),i.first);
		}

	return returnwords;
}


vector<string> patternMatcher(string pattern, string str)
{
	string ns = "";
	char inverted = 0;
	if(str[0] == 'y')
	{
		inverted = 1;
		for(auto i:pattern)
			if(i == 'y')
				ns+='x';
			else
				ns+='y';
		pattern = ns;
	}


	int xlength = 0,ylength=0, xs = 0, ys = 0, rem;
	vector<string> validornot;

	for(auto i:pattern)
	{
		if(i == 'x')
			xs+=1;
		else
			ys+=1;
	}

	if(xs == 0 || ys == 0)
		return {};

	while(xlength<str.length())
	{
		xlength+=1;
		
		rem = (str.length() - (xlength*xs))%(ys);
		if(rem == 0)
		{
			ylength = (str.length() - (xlength*xs))/(ys);
			validornot = checkValidity(xlength, ylength, str, pattern, inverted);
			if(!validornot.empty())
				return validornot;
		}

	}
	return {};
}


int main()
{
	string str = "baddaddoombaddadoomibaddaddoombaddaddoombaddaddoombaddaddoomibaddaddoomibaddaddoom";
	string pattern = "xyxxxyyx";
	vector<string> pat = patternMatcher(pattern, str);

	for(string i:pat)
		cout<<i<<" ";
	cout<<endl;
}

