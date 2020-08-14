#include <vector>
using namespace std;

void merge(vector<int> &array, int f, int mid, int l)
{
	vector<int> left, right;
	for(int i=f;i<=mid;i++)
		left.push_back(array[i]);

	for(int i=mid+1;i<=l;i++)
		right.push_back(array[i]);

	int finalindex = f;
	int i=0,j=0;

	while(i<left.size() && j<right.size())
	{
		if(left[i]<right[j])
		{
			array[finalindex] = left[i];
			i+=1;
			finalindex+=1;
		}
		else if(left[i]>right[j])
		{
			array[finalindex] = right[j];
			j+=1;
			finalindex+=1;
		}
		else
		{
			array[finalindex] = left[i];
			i+=1;
			finalindex+=1;
			array[finalindex] = right[j];
			j+=1;
			finalindex+=1;
		}
	}

	while(i<left.size())
	{
		array[finalindex] = left[i];
		i+=1;
		finalindex+=1;
	}

	while(j<right.size())
	{
		array[finalindex] = right[j];
		j+=1;
		finalindex+=1;
	}
}

void mergeSort(vector<int> &array, int f, int l)
{
	int mid;
	if(f<l)
	{
		mid = (f+l)/2;
		mergeSort(array, f, mid);
		mergeSort(array, mid+1, l);
		merge(array, f, mid, l);
	}
}


vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo)
{
	mergeSort(arrayOne, 0, arrayOne.size()-1);
	mergeSort(arrayTwo, 0, arrayTwo.size()-1);

	// The same program can be written in a cleaner way. Refer to video.
	int i = 0,j = 0;
	int mindiff = INT_MAX;
	vector<int> retarr = {0,0};
	while((i<arrayOne.size()-1) && (j<arrayTwo.size()-1))
	{
		if(abs(arrayOne[i] - arrayTwo[j]) < mindiff)
		{
			retarr[0] = arrayOne[i];
			retarr[1] = arrayTwo[j];
			mindiff = abs(arrayOne[i] - arrayTwo[j]);
		}
		if(arrayOne[i]<arrayTwo[j])
			i+=1;
		else
			j+=1;
	}
	if(i == arrayOne.size()-1)
	{
		while(j<arrayTwo.size())
		{
			if(abs(arrayOne[i] - arrayTwo[j]) < mindiff)
			{
				retarr[0] = arrayOne[i];
				retarr[1] = arrayTwo[j];
				mindiff = abs(arrayOne[i] - arrayTwo[j]);
			}
			j+=1;
		}
	}
	else if(j == arrayTwo.size()-1)
	{
		while(i<arrayOne.size())
		{
			if(abs(arrayOne[i] - arrayTwo[j]) < mindiff)
			{
				retarr[0] = arrayOne[i];
				retarr[1] = arrayTwo[j];
				mindiff = abs(arrayOne[i] - arrayTwo[j]);
			}
			i+=1;
		}
	}
	return retarr;
}
