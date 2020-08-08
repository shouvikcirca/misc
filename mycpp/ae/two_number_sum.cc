#include <bits/stdc++.h>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
	unordered_map<int,bool> present;
	for(int i=0;i<array.size();i++)
	{
		if(present.count(targetSum - array[i]))
			return {array[i], targetSum - array[i]};
		else
			present[array[i]] = true;
	}
	return {};
}
