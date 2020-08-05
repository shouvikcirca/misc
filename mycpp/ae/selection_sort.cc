#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int> array)
{
	if(array.size()<2)
		return array;

	int temp, min;

	for(int i=0;i<array.size()-1;i++)
	{
		min = i;
		for(int j = i+1;j<array.size();j++)
		{
			if(array[j]<array[min])
				min = j;
		}
		if(min!=i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
	return array;
}
