#include <vector>
#include <climits>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array)
{
	int temp, j, maxind;

	for(int i=0;i<3;i++)
	{
		maxind = 0;
		for(j=1;j<array.size()-i;j++)
			if(array[j]>array[maxind])
				maxind = j;

		temp = array[j-1];
		array[j-1] = array[maxind];
		array[maxind] = temp;
	}
	return {array[array.size()-3], array[array.size()-2], array[array.size()-1]};
}
