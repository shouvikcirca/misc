#include <vector>
using namespace std;

int partition(vector<int> &array, int k, int f, int l)
{
	int pivot = l, p = f-1, temp;

	for(int j=f;j<l;j++)
	{
		if(array[j]<array[pivot])
		{
			temp = array[++p];
			array[p] = array[j];
			array[j] = temp;
		}
	}
	temp = array[++p];
	array[p] = array[pivot];
	array[pivot] = temp;

	if ((p) == k-1)
		return array[p];

	if((p) > k-1)
		return partition(array, k, f, p-1);

	return partition(array, k, p+1, l);
}

int quickselect(vector<int> array, int k)
{
	return partition(array, k, 0, array.size()-1);
}

