#include<bits/stdc++.h>
#include <vector>
#include<unordered_map>
using namespace std;

vector<string> checkxvalidity(string s, int xs)
{
	string c;
	for(int i=1;i<=(s.length()/xs);i++)
	{
		c = "";
		for(int j=1;j<=xs;j++)
			c+=s.substr(0,i);
		if(c == s)
			return {s.substr(0,i),""};
	}
	return {}; //	
}

vector<string> checkdualvalidity(string s, int xs, int ys, int xlength, int ylength, string pattern)
{
	int index=0;
	int patternind = 0;	
	string ns = "";
	string x="",y="";
	string prevx="", prevy="";

	while(index<s.length())
	{
		if(pattern.at(patternind) == 'x')
		{
			x = s.substr(index, xlength);
			if(prevx=="")
				prevx = x;
			else if(x!=prevx)
				return {};
			ns = ns + x;
			index = index + xlength;
		}
		else if(pattern.at(patternind) == 'y')
		{
			y = s.substr(index, ylength);
			if(prevy=="")
				prevy = y;
			else if(y!=prevy)
				return {};
			ns = ns + y;
			index = index + ylength;
		}
		patternind+=1;
	}

	if (patternind<=pattern.length()-1)
		return {};

	if(ns == s)
	{
		if((x=="" && xs>=1) || (y=="" && ys>=1))
			return {};
		else
			return {x,y};
	}

	else
		return {};
}

vector<string> patternMatcher(string pattern, string s)
{

	if(s.length() == 0 || pattern.length() == 0)
		return {};

	string ns = "";
	char inverted = 0;
	if(s.at(0) == 'y')
	{
		inverted = 1;
		for(int i=0;i<pattern.length();i++)
		{
			if(pattern.at(i) == 'y')
				ns+='x';
			else
				ns+='y';
		}
		pattern = ns;
	}

	int xs = 0, ys = 0;

	for(int i=0;i<pattern.length();i++)
	{
		if(pattern.at(i) == 'x')
			xs+=1;
		else
			ys+=1;
	}

	vector<string> returnvec;
	string temp;
	if(ys == 0)
	{
		returnvec = checkxvalidity(s, xs);
		if(inverted == 1)
		{
			temp = returnvec[0];
			returnvec[0] = returnvec[1];
			returnvec[1] = temp;
		}
		return returnvec;
	}


	int xlength = 0, ylength = 0;

	for(int i = 1;i<s.length();i++)
	{
		xlength = i;
		ylength = (s.length() - (xlength*xs))%ys;
		if(ylength == 0)
			ylength = (s.length() - (xlength*xs))/ys;
		else
			continue;
		if((xs*xlength + ys*ylength)>s.length())
			return {}; //
		returnvec = checkdualvalidity(s, xs, ys, xlength, ylength, pattern);
		if(returnvec.empty())
			continue;
		else
			break;
	}

	if(returnvec.empty())
		return {}; //

	if(inverted == 1)
	{
		temp = returnvec[0];
		returnvec[0] = returnvec[1];
		returnvec[1] = temp;
	}
	return returnvec;
}

int main()
{
	vector<string> s;
	s = patternMatcher("xyxxxyyx","baddaddoombaddadoomibaddaddoombaddaddoombaddaddoombaddaddoomibaddaddoomibaddaddoom");


	for(auto i:s)
		cout<<i<<" ";
	cout<<endl;

}
