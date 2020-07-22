#include <bits/stdc++.h>
using namespace std;

int findSmallest(vector<int> array, int i)
{
	int min = array[i];
	for(int j=i+1;j<array.size();j++)
		if(array[j]<min)
			min = array[j];
	return min;
}

int findLargest(vector<int> array, int i)
{
	int max =  array[i];
	for(int j=i-1;j>=0;j--)
		if(array[j]>max)
			max = array[j];
	return max;
}


vector<int> subarraySort(vector<int> array)
{
	int smallest = array[0],largest = array[array.size()-1];
	int f = 0;
	for(int i=0;i<array.size()-1;i++)
	{
		if(array[i] > array[i+1])
		{
			f = 1;
			smallest = findSmallest(array, i);
			break;
		}

	}

	if(f == 0)
		return {-1, -1};

	for(int i=array.size()-1;i>0;i--)
	{
		if(array[i] < array[i-1])
		{
			largest = findLargest(array, i);
			break;
		}
	}

	int start, end;
	for(int i=0;i<array.size();i++)
	{
		if(array[i]>smallest)
		{
			start = i;
			break;
		}
	}

	for(int i=array.size()-1;i>=0;i--)
	{
		if(array[i]<largest)
		{
			end = i;
			break;
		}
	}
	return {start, end};
}

int main()
{
	vector<int> array {1,2,4,7,10,11,7,12,6,7,16,18,19};
	vector<int> startend;
	startend = subarraySort(array);

	for(int i:startend)
		cout<<i<<" ";
	cout<<endl;
}





