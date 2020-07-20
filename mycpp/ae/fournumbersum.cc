#include <bits/stdc++.h>
using namespace std;

void formcombination(vector<vector<int>> &finalvect, vector<vector<int>> ummap, int i, int j)
{
	for(auto entry: ummap)
		finalvect.push_back({entry[0], entry[1], i, j});
}

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum)
{
	unordered_map<int, vector<vector<int>>> um;
	vector<vector<int>> finalvect;
	int diff,sum;

	for(int i=1;i<array.size()-1;i++)
	{
		for(int j=i+1;j<array.size();j++)
		{
			diff = targetSum - (array[i]+array[j]);
			if(um.count(diff))
				formcombination(finalvect, um[diff], array[i], array[j]);
		}
		for(int k=0;k<i;k++)
		{
			sum = array[i]+array[k];
			if(um.count(sum))
				um[sum].push_back({array[i], array[k]});
			else
				um[sum] = {{array[i], array[k]}};
		}
	}
	return finalvect;
}

int main()
{
	vector<int> array {7,6,4,-1,1,2};
	int target = 16;
	vector<vector<int>> fs;

	fs = fourNumberSum(array, target);
	for(auto i:fs)
	{
		for(auto j:i)
			cout<<j<<" ";
		cout<<endl;
	}
}

