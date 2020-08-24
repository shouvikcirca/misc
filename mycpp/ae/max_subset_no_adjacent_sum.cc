#include <bits/stdc++.h>
using namespace std;

//O(n) time and O(n) space
int maxSubsetSumNoAdjacent(vector<int> array)
{
	if(array.size() == 0)
		return 0;

	vector<vector<int>> sums (array.size(), vector<int> (2,0));
	int maxtillhere = 0, it;

	for(int i=0;i<array.size();i++)
	{
		it = i-2;
		sums[i][0] = it<0?array[i]:array[i]+sums[it][1];
		sums[i][1] = max(sums[i][0],maxtillhere);
		maxtillhere = max(sums[i][0],maxtillhere);
	}
	return sums[sums.size()-1][1];
}

//0(n) time and 0(1) space
int optimized_ maxSubsetSumNoAdjacent(vector<int> array)
{
	if(array.size() == 0)
		return 0;

	int maxtillhere = 0, it, sum;
	int prevsum, prevprevsum, prevmth = INT_MIN, prevprevmth = INT_MIN;

	for(int i=0;i<array.size();i++)
	{
		it = i-2;
		sum = it<0?array[i]:array[i]+prevprevmth;
		maxtillhere = max(sum,prevprevmth);
		prevprevmth = max(prevprevmth, prevmth);
		prevprevsum = prevsum;
		prevsum = sum;
		prevmth = max(prevmth, maxtillhere);
	}
	return prevmth;
}

int main()
{
	int s = maxSubsetSumNoAdjacent({75});
	cout<<s<<endl;
}
