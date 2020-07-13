#include<bits/stdc++.h>
using namespace std;

int longestPeak(vector<int> array) 
{
	vector<vector<int>> increasing;
	vector<vector<int>> decreasing;
	int start = 0, end = 0, lpeak = 0;

	for(int i=1;i<array.size();i++)
	{
		if(array[i] > array[i-1])
			end = i;
		else
		{
			increasing.push_back({start,end, (end-start+1)});
			start = i;
		}
	}

	start = end = array.size()-1;
	for(int i=array.size()-2;i>=0;i--)
	{
		if(array[i] > array[i+1])
			end = i;
		else
		{
			for(auto j: increasing)
			{
				if((end == j[1]) && (j[0]<j[1]) && (start - j[0] + 1 )>lpeak)
					lpeak = start - j[0] + 1;
			}
			start = i;
		}
	}
	return lpeak;
}

int main()
{
	vector<int> array {1,2,3,3,4,0,10,6,5,-1,-3,2,3};
	cout<<longestPeak(array)<<endl;
}


