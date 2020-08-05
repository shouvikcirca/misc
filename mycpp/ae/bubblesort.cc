#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int> array)
{
	if(array.size()<2)
		return array;

	int temp,f;

	for(int i=0;i<array.size()-1;i++)
	{
		f = 0;
		for(int j=0;j<array.size()-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				f = 1;
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		if(f == 0)
			break;
	}
	return array;
}
