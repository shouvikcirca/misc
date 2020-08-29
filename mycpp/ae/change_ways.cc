#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
	vector<int> coins (n+1,0);
	coins[0] = 1;

	for(int i=0;i<denoms.size();i++)
	{
		for(int j=1;j<coins.size();j++)
		{
			if(j>=denoms[i])
				coins[j] = coins[j] + coins[j-denoms[i]];
		}
	}
	return coins.back();
}
