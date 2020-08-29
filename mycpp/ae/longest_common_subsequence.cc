#include <bits/stdc++.h>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2)
{
	vector<vector<int>> lcs (str1.length()+1, vector<int> (str2.length()+1,0));

	for(int i=1;i<lcs.size();i++)
	{
		for(int j=1;j<lcs[0].size();j++)
		{
			if(str1.at(i-1) == str2.at(j-1))
				lcs[i][j] = lcs[i-1][j-1]+1;
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);					
		}
	}

	
	vector<char> seq (lcs.back().back(), ' ');

	int i=lcs.size()-1, j = lcs[0].size()-1;
	int ind = seq.size()-1;

	while(i>0 && j>0)
	{
		if(str1.at(i-1) == str2.at(j-1))
		{
			seq[ind--] = str1.at(i-1);
			i-=1;
			j-=1;
		}
		else
		{
			if(lcs[i-1][j]>lcs[i][j-1])
				i-=1;
			else
				j-=1;

		}
	}

	return seq;

}

int main()
{
	string s1 = "ABCDEFG";
	string s2 = "APPLES";
	vector<char> seq = longestCommonSubsequence(s1,s2);
	for(char i:seq)
		cout<<i<<" ";
	cout<<endl;
	
	
}

