#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
	int f,temp;
	for(int i=0;i<array.size()-1;i++)
	{
		f = 0;
		for(int j=0;j<array.size()-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				f = 1;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		if(f == 0)
			break;
	}

	int l,r,sum;
	vector<vector<int>> tripletarr;

	for(int i=0;i<array.size()-2;i++)
	{
		l = i+1;
		r = array.size()-1;
		while(l<r)
		{
			sum = array[i]+array[l]+array[r];
			if(sum == targetSum)
			{
				tripletarr.push_back({array[i],array[l],array[r]});
				l+=1;
				r-=1;
			}
			else if(sum<targetSum)
				l+=1; 
			else
				r-=1;						
		}
	}
	return tripletarr;
}
