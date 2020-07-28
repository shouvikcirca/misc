#include <bits/stdc++.h>
using namespace std;

int waterArea(vector<int> heights)
{
	
	if(heights.size() == 1|| heights.empty()) return 0;

	vector<int> leftmax (heights.size(),0);
	int maxel = leftmax[0];

	for(int i=1;i<heights.size();i++)
	{
		maxel = max(maxel, heights[i-1]);
		leftmax[i] = maxel;
	} 

	vector<int> rightmax (heights.size(),0);
	maxel = rightmax[heights.size()-1];

	for(int i=heights.size()-2;i>=0;i--)
	{
		maxel = max(maxel, heights[i+1]);
		rightmax[i] = maxel;
	}

	vector<int> finalarray;
	int m, sum = 0;

	for(int i=0;i<heights.size();i++)
	{
		m = min(leftmax[i],rightmax[i]);
		if(heights[i]<m)
			sum+=(m - heights[i]);
	}
	return sum;
}

int main()
{
	cout<<waterArea({0,8,0,0,5,0,0,10,0,0,1,1,0,3})<<endl;
}

