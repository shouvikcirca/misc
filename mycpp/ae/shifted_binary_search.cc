#include <vector>
using namespace std;

int shiftedBinarySearch(vector<int> array, int target)
{
	int left = 0;
	int right = array.size()-1;
	int mid;

	while(left<=right)
	{
		mid = (left+right)/2;
		if(array[mid] == target)
			return mid;

		else if(array[left] <= array[mid])
		{
			if(target>=array[left] && target<array[mid])
				right = mid-1;
			else
				left = mid+1;
		}
		else
		{
			if(target>array[mid] && target<=array[right])
				left = mid+1;
			else
				right = mid-1;
		}
	}

	return -1;
}

