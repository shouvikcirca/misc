#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int> array)
{
	if(array.size()<2)
		return array;

	int key,j;

	for(int i=1;i<array.size();i++)
	{
		key = array[i];
		for(j=i-1;j>=0;j--)
		{
			if(array[j]>key)
				array[j+1] = array[j];
			else
				break;
		}
		array[j+1] = key;
	}
	return array;
}
