#include <vector>
using namespace std;

void maxheapify(vector<int> &array, int id, int heapsize)
{
	int l = 2*id+1, r = 2*id+2, largest = id, temp;

	if(l<=heapsize && array[l]>array[largest])
		largest = l;
	if(r<=heapsize && array[r]>array[largest])
		largest = r;

	if(largest!=id)
	{
		temp = array[largest];
		array[largest] = array[id];
		array[id] = temp;
		maxheapify(array, largest, heapsize);
	}
}

void buildHeap(vector<int> &array)
{
	int startid = (array.size()/2)-1;

	for(int i=startid;i>=0;i--)
		maxheapify(array, i, array.size()-1);
}

vector<int> heapSort(vector<int> array)
{
	int temp;
	int heapsize = array.size()-1;
	buildHeap(array);
	for(int i = array.size()-1;i>0;i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapsize-=1;
		maxheapify(array, 0, heapsize);
	}
	return array;
}
