#include <vector>
using namespace std;

void computePermutations(vector<int> &array, vector<vector<int>> &permutations, int k)
{
	if(k==array.size())
		return;

	int temp;
	vector<int> currarr;

	for(int i=k;i<array.size();i++)
	{
		temp = array[k];
		array[k] = array[i];
		array[i] = temp;

		computePermutations(array, permutations, k+1);

		if(k == array.size()-1)
		{
			while(!currarr.empty())
				currarr.pop_back();

			for(int i:array)
				currarr.push_back(i);

			permutations.push_back(currarr);
		}
		temp = array[k];
		array[k] = array[i];
		array[i] = temp;
	}
}

vector<vector<int>> getPermutations(vector<int> array)
{
	vector<vector<int>> permutations;
	computePermutations(array, permutations, 0);
	return permutations;
}
