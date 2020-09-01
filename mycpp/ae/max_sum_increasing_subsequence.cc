#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array)
{
	vector<vector<int>> sums;
	sums.push_back({array[0],-1});
	int maxsum = array[0];
	int maxsumindex = 0;
	int preval,currsum,j;

	for(int i=1;i<array.size();i++)
	{
		preval = -1;
		currsum = array[i];
		j = array[i]>array[i-1]?i-1:i-2;
		for(;j>=0;j--)
		{
			if((array[j]<array[i]) && (array[i]+sums[j][0]>currsum))
			{
				currsum = array[i]+sums[j][0];
				preval = j;
			}
		}
		cout<<"---"<<currsum<<endl;
		if(currsum > maxsum)
		{
			maxsum = currsum;
			maxsumindex = i;
		}
		sums.push_back({currsum,preval});
	}

	vector<int> elements;
	int ind = maxsumindex;
	int el,ni;

	while(ind>=0)
	{
		el = array[ind];
		elements.insert(elements.begin(),el);
		ni = sums[ind][1];
		ind = ni;

	}

	return {{maxsum},  elements};
}
