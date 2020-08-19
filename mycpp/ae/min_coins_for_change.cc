#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
	vector<int> coinarray (n+1, INT_MAX);
	coinarray[0]=0;

	for(int i=0;i<denoms.size();i++)
	{
		for(int j=0;j<coinarray.size();j++)
		{
			if(j<denoms[i])
				continue;
			if(coinarray[j-denoms[i]] == INT_MAX) 
				coinarray[j] = min(coinarray[j], coinarray[j-denoms[i]] );
			else
				coinarray[j] = min(coinarray[j], 1+coinarray[j-denoms[i]] );
		}
	}
	return coinarray.back()!=INT_MAX?coinarray.back():-1;
}
